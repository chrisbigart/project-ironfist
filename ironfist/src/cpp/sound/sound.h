#ifndef SOUND_H
#define SOUND_H

#pragma pack(push, 1)
//typedef void * 	H3DPOBJECT;
//typedef void * 	H3DSAMPLE;
typedef void * 	HDIGDRIVER;
//typedef unsigned int 	HPROVIDER;
//typedef void * 	HSAMPLE;
//typedef void * 	HSTREAM;

class soundManager : public baseManager
	{
public:
	//managerVtable *vtable;

	//virtual int Open(int);
	//virtual void Close();
	//virtual int Main(tag_message&);
/*
	baseManager *next;
	baseManager *prev;*/
	//int type;
	//int idx;
	//char name[30];
	//int ready;

	int redbookStatus;
	HDIGDRIVER hdidriver;
	int field_3E;
	char _0[22];	
	void * hsamples[14];  //HSAMPLE hsamples[14];
	int field_90;
	int field_94;
	int numSamplesAllocated;
	char _1[84];
	char _2[1152];
	int field_570;
	int _3;
	int field_578;
	char currentTrack;
	char _4[267];
	int aiMusicOff;
	int volRelated;
	int _5;
	int field_694;
	int field_698;
	__int16 outputDeviceID;
	int field_69E;
	int usingRedbookRelated;
	int field_6A6;
	float field_6AA;
	int someTick;
	soundManager();

	void SwitchAmbientMusic(int track);
	void PlayAmbientMusic(int, long, int);
	void CDPlay(int track_number, signed int a3, int a4, int a5);
	void CDStop();
	void CDSetVolume(int, int);
	void CDSetVolume_orig(int, int);
	void CDStartup(void);
	void CDStartup_orig(void);
	int ConvertVolume(int, int);
	int ConvertVolume_orig(int, int);
	void ServiceSound();
	void StopAllSamples(int);
};

#pragma pack(pop)
extern soundManager *gpSoundManager;

extern unsigned char giTerrainToMusicTrack[];

extern struct SAMPLE2 __fastcall LoadPlaySample(char *);
extern void __fastcall WaitEndSample(struct SAMPLE2, int);

#endif