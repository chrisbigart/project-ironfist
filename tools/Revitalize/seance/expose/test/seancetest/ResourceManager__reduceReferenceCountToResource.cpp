void __thiscall ResourceManager::reduceReferenceCountToResource(ResourceManager *this, AbstractResource *res)
{
  if ( !this->isFreeingAllResources )
  {
    if ( res )
    {
      --res->referenceCount;
      if ( res->referenceCount <= 0 )
      {
        ResourceManager::removeFileFromList(this, res);
        if ( res )
          res->vtable->cleanUp(res, 1);
      }
    }
  }
}
