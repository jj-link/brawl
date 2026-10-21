#include <gm/gm_global.h>
#pragma force_active on

extern "C" void fn_801593A0() {
    char* p = (char*)g_GameGlobal->m_advData;
    *(int*)(p + 0x4910) = 0;
    *(char*)(p + 0x4916) = 0;
    *(short*)(p + 0x4920) = 0;
    *(char*)(p + 0x4914) = 0;
    *(char*)(p + 0x4915) = 0;
    *(int*)(p + 0x4918) = 0;
    *(int*)(p + 0x491C) = 0;
}
