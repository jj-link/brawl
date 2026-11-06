#include <it/item.h>
#include <gm/gm_global.h>
#include <if/if_mngr.h>
#pragma force_active on
extern "C" const float lbl_88_rodata_0[];
extern "C" unsigned int __cvt_fp2unsigned(float);
extern "C" void fn_800E14A4(void*, unsigned int, int);
extern "C" void fn_800E3684(void*, int);
inline float calc(float x, float low, float high, float scale) {
    return scale * ((x - low) / (high - low));
}
extern "C" void fn_88_2598(void* arg) {
    unsigned char* self = (unsigned char*)arg;
    const float* k = lbl_88_rodata_0;
    BaseItem* item = *(BaseItem**)(self + 0x1ec);
    if (item && ((((unsigned char*)item)[0x2c] >> 6) & 1) && self[0x2a0] && g_GameGlobal->m_modeMelee) {
        float value = item->getParamFloat(2);
        IfMngr* manager = g_IfMngr;
        fn_800E14A4(manager->m_ifPlayers[((unsigned char*)manager)[0x6a]], __cvt_fp2unsigned(value), 0);
        if (value != *(float*)(self + 0x1f8)) {
            float amount = calc(value - *(float*)(self + 0x1f8), k[20], k[11], k[21]);
            if (amount < k[0]) amount = k[0];
            if (amount > k[22]) amount = k[22];
            manager = g_IfMngr;
            unsigned char* player = (unsigned char*)manager->m_ifPlayers[((unsigned char*)manager)[0x6a]];
            if (*(unsigned int*)(player + 0x1c) == *(unsigned int*)(player + 0x18)) {
                *(float*)(player + 0x264) = amount;
                fn_800E3684(player, 1);
            }
            *(float*)(self + 0x1f8) = value;
        }
    }
}