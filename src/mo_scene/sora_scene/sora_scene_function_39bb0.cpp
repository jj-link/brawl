#pragma force_active on
#include <gm/gm_global.h>
#include <st/loader/st_loader_manager.h>
#include <mu/wifi/mu_wifi_interface.h>
#include <types.h>

extern "C" {
void fn_8005033C(void*);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int, int);
u8 fn_1_383C0();
void fn_800D2C50(void*, u8, u16*);
void fn_8010F960(u16, void*, void*, int);
extern const float lbl_1_rodata_2408;
}

struct ModeFlags {
    u8 gameMode : 6;
    u8 rest : 2;
};

struct ModeCount {
    u8 count : 3;
    u8 rule : 3;
    u8 rest : 2;
};

struct ModeFlagB {
    u8 high : 5;
    u8 enabled : 1;
    u8 low : 2;
};

extern "C" void fn_1_39BB0() {
    u8* mode = (u8*)g_GameGlobal->m_modeMelee;
    u8* select = (u8*)g_GameGlobal->m_selCharData;
    g_GameGlobal->getGlobalRecordMenuDatap();
    fn_8005033C(mode);

    ((ModeFlags*)(mode + 8))->gameMode = 19;
    *(u16*)(mode + 0x1A) = 0x37;
    ((ModeCount*)(mode + 9))->count = 0;
    *(u32*)(mode + 0x20) = 0;
    mode[0x13] = 0;
    *(float*)(mode + 0x4C) = lbl_1_rodata_2408;
    ((ModeFlagB*)(mode + 0x0B))->enabled = 0;
    *(u32*)(mode + 0x34) = 0;
    *(u32*)(mode + 0x30) = 0;
    *(u32*)(mode + 0x38) = 0;
    *(u32*)(mode + 0x3C) = 0;
    mode[0x16] = 0;

    u8* in = select;
    u8* out = mode;
    u8* name = mode + 0xA4;
    u8* flags = mode + 0xB4;
    int loaderOffset;
    int i = 0;
    loaderOffset = 0;
    do {
        if (i == 0) {
            out[0x98] = in[0xB8];
            out[0x99] = in[0xB9];
            out[0xA3] = in[0xC3];
            int color = in[0xBD];
            int kind = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(out[0x98]);
            out[0x9D] = kind == 0x28 ? 0 : getFighterColorFileNo__6muMenuFiii(kind, color);
            out[0x9E] = in[0xBD];
            out[0xB0] = in[0xD0];
            out[0x9F] = in[0xBF];
            ((s8*)out)[0x9C] = -1;

            if (out[0x99] == 0 && *(u16*)(out + 0xA4) == 0) {
                void* wifi = g_muWifiInterfaceTask;
                u8 index = fn_1_383C0();
                if (index == 0xFF) index = 4;
                fn_800D2C50(wifi, index, (u16*)name);
            }

            if (*(u16*)(out + 0xA4) == 0) {
                *flags &= ~0x20;
            } else {
                *flags |= 0x20;
            }

            stLoaderPlayer* loader = *(stLoaderPlayer**)((u8*)g_stLoaderManager + loaderOffset);
            if (loader != 0) ((u8*)loader)[0x5D] |= 4;
            loader = *(stLoaderPlayer**)((u8*)g_stLoaderManager + loaderOffset);
            if (loader != 0) ((u8*)loader)[0x5D] &= ~0x08;
        } else {
            out[0x99] = 3;
            stLoaderPlayer* loader = *(stLoaderPlayer**)((u8*)g_stLoaderManager + loaderOffset);
            if (loader != 0) ((u8*)loader)[0x5D] &= ~0x04;
            loader = *(stLoaderPlayer**)((u8*)g_stLoaderManager + loaderOffset);
            if (loader != 0) ((u8*)loader)[0x5D] |= 8;
        }

        ++i;
        in += 0x5C;
        out += 0x5C;
        name += 0x5C;
        flags += 0x5C;
        loaderOffset += 4;
    } while (i < 7);

    fn_8010F960(*(u16*)(mode + 0x1A), mode + 0x1C, mode + 0x5C, 0);
}
