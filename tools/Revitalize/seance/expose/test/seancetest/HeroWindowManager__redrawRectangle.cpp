void __thiscall HeroWindowManager::redrawRectangle(HeroWindowManager *this, int offsetX, int offsetY, unsigned int width, int height)
{
  HeroWindowManager *thisa; // esi@1

  thisa = this;
  mouseManager->couldBeShowMouse = 0;
  yieldToGlobalUpdater();
  renderBitmapToScreenWithWinG(thisa->screenBuffer, offsetX, offsetY, width, height, offsetX, offsetY);
  mouseManager->couldBeShowMouse = 1;
  yieldToGlobalUpdater();
}
