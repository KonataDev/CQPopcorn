#include <cqimpl.h>

bool cqimpl_initialize(cqapi_impl_t mode)
{
  if (mode < 1 || mode > 2) return false;

  // override virtual functions
  for(size_t i; i < sizeof(_implementions) / 3; ++i)
    *(_implementions[0][i]) = _implementions[mode][i];

  return true;
}

cqapi_impl_t cqimpl_mode()
{
}
