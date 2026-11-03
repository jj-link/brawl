#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" int sprintf(char*, const char*, ...);
extern "C" char lbl_3_data_858[];

extern "C" void fn_3_8F0C(unsigned char* self) {
    unsigned char* src = (unsigned char*)g_GameGlobal->m_tournamentData;
    unsigned char* entry = src + 8;
    unsigned char* dst = self;
    char* name = (char*)(self + 0x108);
    u32 i;

    *(u32*)(self + 0x9E8) = src[0];
    *(u32*)(self + 0x9E0) = src[1];
    *(u32*)(self + 0x9E4) = src[4];
    *(u32*)(self + 0xADC) = src[5];
    *(u32*)(self + 0xA0C) = src[6];
    self[0xA12] = 0;

    for (i = 0; i < *(u32*)(self + 0x9E8);) {
        switch (entry[0]) {
        case 0:
            *(s32*)(dst + 0x104) = 0;
            break;
        case 1:
            *(s32*)(dst + 0x104) = 1;
            self[0xA12] = 1;
            break;
        case 2:
            *(s32*)(dst + 0x104) = 2;
            break;
        }
        sprintf(name, lbl_3_data_858, entry + 2);
        name += 0x28;
        i++;
        dst[0x128] = entry[0x17];
        dst[0x129] = entry[0x18];
        dst[0x12A] = entry[0x19];
        *(s32*)(dst + 0x120) = entry[0x1A];
        dst[0x124] = entry[0x1C];
        *(u16*)(dst + 0x126) = *(u16*)(entry + 0x1E);
        entry += 0x28;
        dst += 0x28;
    }
}