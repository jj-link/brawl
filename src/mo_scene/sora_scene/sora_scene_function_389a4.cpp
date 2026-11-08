#include <gm/gm_global.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" void* fn_800CB834(void* self);

struct TopBits {
    unsigned char hi : 3;
    unsigned char lo : 5;
};

extern "C" void fn_1_389A4(void)
{
    unsigned char* src = (unsigned char*)fn_800CB834(g_muWifiInterfaceTask);
    unsigned char* a = (unsigned char*)g_GameGlobal->m_selCharData;
    unsigned char* b = (unsigned char*)g_GameGlobal->m_setRule;
    a[0x33] = src[0];
    ((TopBits*)(a + 0x29))->hi = src[1];
    *(int*)(a + 0x40) = src[2];
    *(int*)(a + 0x44) = src[3];
    b[0x2] = src[1];
    b[0x3] = src[2];
    b[0x4] = src[3];
    b[0x5] = src[4];
    b[0x6] = src[5];
    b[0x8] = src[6];
    b[0x9] = src[7];
    b[0xB] = src[8];
    b[0xC] = src[9];
}
