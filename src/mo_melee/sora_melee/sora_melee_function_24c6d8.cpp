#include <StaticAssert.h>
#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

struct unk_14_t {
    char _0[0x14];
    u8 m_14;
};

struct fn_27_24C6D8_param_t {
    char _0[0x44];
    unk_14_t* m_44;
};

extern "C" {
void fn_27_24C6FC(fn_27_24C6D8_param_t* param, gmGlobalCorps* corps);
}

extern "C" void fn_27_24C6D8(fn_27_24C6D8_param_t* param) {
    if (param->m_44->m_14 != 4) {
        return;
    }
    fn_27_24C6FC(param, g_GameGlobal->m_corps);
}
