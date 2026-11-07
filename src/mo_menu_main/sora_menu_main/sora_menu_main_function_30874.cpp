#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004DA80(GameGlobal*, int);

struct HighBit {
    unsigned char high : 1;
    unsigned char second : 1;
    unsigned char rest : 6;
};

struct MenuMain {
    unsigned char pad[0x40];
    unsigned char* data;
};

extern "C" void fn_2_30874(MenuMain* self, int index)
{
    unsigned char* src = (unsigned char*)fn_8004DA80(g_GameGlobal, index);
    unsigned char* dst = self->data;
    dst[0x168] = src[0];
    dst[0x169] = src[1];
    dst[0x16a] = src[2];
    dst[0x16b] = src[9];
    dst[0x16c] = src[10];
    dst[0x16d] = src[6];
    dst[0x16e] = src[7];
    dst[0x16f] = src[8];
    dst[0x170] = src[3];
    dst[0x171] = src[4];
    dst[0x172] = src[5];
    ((HighBit*)(dst + 0x174))->high = ((HighBit*)(src + 0xb))->high;
    dst = self->data;
    dst[0x175] = src[0x1c];
    dst[0x176] = src[0x1d];
    dst[0x177] = src[0x1e];
    dst[0x178] = src[0x17];
    dst[0x179] = src[0x18];
    dst[0x17a] = src[0x19];
    dst[0x17b] = src[0x14];
    dst[0x17c] = src[0x15];
    dst[0x17d] = src[0x16];
    dst[0x17e] = src[0x1b];
    dst[0x17f] = src[0x1a];
    ((HighBit*)(dst + 0x181))->high = ((HighBit*)(src + 0x1f))->second;
    ((HighBit*)(dst + 0x181))->second = ((HighBit*)(src + 0x1f))->high;
    dst = self->data;
    dst[0x182] = src[0x12];
    dst[0x183] = src[0xf];
    dst[0x184] = src[0x13];
    dst[0x185] = src[0xd];
    dst[0x186] = src[0xc];
    dst[0x187] = src[0xe];
    dst[0x188] = src[0x10];
    dst[0x189] = src[0x11];
    dst = self->data;
    dst[0x18f] = src[0x20];
    dst[0x190] = src[0x21];
    dst[0x191] = src[0x22];
    dst[0x192] = src[0x23];
    dst[0x193] = src[0x2a];
    dst[0x194] = src[0x2b];
    dst[0x195] = src[0x27];
    dst[0x196] = src[0x28];
    dst[0x197] = src[0x29];
    dst[0x198] = src[0x24];
    dst[0x199] = src[0x25];
    dst[0x19a] = src[0x26];
    ((HighBit*)(dst + 0x19b))->high = ((HighBit*)(src + 0x2c))->high;
}
