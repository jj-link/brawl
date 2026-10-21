#include <gf/gf_module.h>
#pragma force_active on

extern gfModuleManager* lbl_805A0038;

gfModuleManager* gfModuleManager::getInstance()
{
    return lbl_805A0038;
}
