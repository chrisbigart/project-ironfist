{
  Bitmap *thisa; // esi@1

  thisa = from;
  yieldToGlobalUpdater();
  blit(thisa, 0, 0, thisa->width, thisa->height, HeroWindowManager::instance->screenBuffer, x, y);
  yieldToGlobalUpdater();
}
