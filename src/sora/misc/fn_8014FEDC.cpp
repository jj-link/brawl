#include <types.h>
#include <gm/gm_global.h>

#pragma force_active on

extern "C" {
u32 fn_8014FEDC(u32 arg0) {
    void* p = *(void**)(reinterpret_cast<char*>(g_GameGlobal) + 0x38);
    u16 val = *reinterpret_cast<u16*>(reinterpret_cast<char*>(p) + 0xA);
    return (val & arg0) != 0;
}
}
