#include "base.h"
#include "game/game.h"
#include "sound/sound.h"
#include "manager.h"

#include <iostream>

//this version is for use with h2cdplay

extern BOOL gbNoSound;
extern BOOL CDPlaying;
extern void __fastcall Process1WindowsMessage();

#define MAXTRACK 64
HANDLE evt[MAXTRACK];

void soundManager::CDStop()
	{
	SetEvent(evt[0]);
	}

int soundManager::ConvertVolume(int weight, int is_music_flag)
	{ //this does not seem to work
	int volume = this->volRelated;
	if(volume < 0 || volume > 10)
		{
		std::cerr << "volume out of bounds";
		return ConvertVolume_orig(weight, is_music_flag);
		}
	SetEvent(evt[50 + volume]);
	return ConvertVolume_orig(weight, is_music_flag);
	}

void soundManager::CDSetVolume(int unknown_control_code, int unknown)
	{ //this does not seem to work
	int volume = this->volRelated;
	if(volume < 0 || volume > 10)
		{
		std::cerr << "volume out of bounds";
		return;
		}
	SetEvent(evt[50 + volume]);
	}

void soundManager::CDPlay(int track_number, signed int a3, int a4, int a5)
	{
	int volume; // eax@20
	unsigned __int32 startmsec; // [sp+10h] [bp-18h]@14

	static bool setup_events = false;
	if(!setup_events)
		{
		char evtnamebuf[1024];
		int i;
		for(i = 0; i < MAXTRACK; i++)
			{
			sprintf(evtnamebuf, "h2cd_play_track#%02d", i);
			evt[i] = CreateEventA(NULL, FALSE, FALSE, evtnamebuf);
			}
		}

	//if(!gbNoSound && this->field_69E && *(_DWORD *)&Data)
	if(!gbNoSound && this->field_69E)// && *(_DWORD *)&Data)
		{
		if(track_number == -1)
			{
			soundManager::CDStop();
			}
		else if(this->currentTrack != track_number || !CDPlaying || a5)
			{
			Process1WindowsMessage();
			soundManager::ServiceSound();
			this->field_694 = track_number;
			this->field_698 = a4;
			SetEvent(evt[track_number]);
			/*
			if(*((_BYTE *)&bSaveMusicPosition + a2))
			a3 = 1;
			soundManager::StopAllSamples(thisa, 1);
			soundManager::CDStop();
			if(!a5 && a3 && *((_DWORD *)dword_4ED0B8 + a2))
			startmsec = *((_DWORD *)dword_4ED0B8 + a2);
			else
			startmsec = *((_DWORD *)ptr + track_number);
			this->redbookStatus = AIL_redbook_play(aStatusCdPositi, startmsec, *((_DWORD *)dword_4ED0B4 + a2));
			if(thisa->redbookStatus != REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION)
			{
			DelayMilli(100);
			thisa->redbookStatus = AIL_redbook_status(aStatusCdPositi);
			if(thisa->redbookStatus != REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION)
			thisa->redbookStatus = AIL_redbook_play(aStatusCdPositi, startmsec, *((_DWORD *)dword_4ED0B4 + a2));
			}*/
			//CDPlaying = 1;
			Process1WindowsMessage();
			soundManager::ServiceSound();
			if(this->volRelated <= 0)
				{
				if(a4 != -1)
					{
					soundManager::CDSetVolume(-1, 0);
					}
				}
			else
				{
				this->volRelated = 10;
				//dword_524BF8 = KBTickCount() + 600;
				volume = soundManager::ConvertVolume(1, 101);
				soundManager::CDSetVolume(volume, 1);
				}
			this->currentTrack = track_number;
			}
		}
	}