#include <string.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_800B96E8(void*, int);

struct Inner {
    int f00;
    int f04;
    int f08;
    char _0c[4];
    int arr[5][7];
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    char fb8[0xa8];
    int f160;
    int f164;
    char f168[0x34];
    char f19c[0xd];
    char _1a9[3];
    int f1ac;
    int f1b0;
    char f1b4;
    char _1b5[3];
    int f1b8;
    char f1bc;
    char _1bd;
    short f1be;
    short f1c0;
    char _1c2[2];
    int f1c4;
    char _1c8[4];
    char f1cc;
    char _1cd[7];
    char f1d4;
};

struct Self {
    char pad[0x40];
    Inner* inner;
};

extern "C" void fn_2_30D90(Self* self) {
    self->inner->f00 = 0;
    self->inner->f04 = 0;
    self->inner->f08 = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            self->inner->arr[i][j] = 0;
        }
    }
    self->inner->f9c = 0;
    self->inner->fa0 = 0;
    self->inner->fa4 = 0;
    self->inner->fa8 = 0;
    self->inner->fac = 0;
    fn_800B96E8((void*)((char*)self->inner + 0xb8), 0xf0);
    self->inner->fb0 = 1;
    self->inner->fb4 = 0;
    self->inner->f160 = 0;
    self->inner->f164 = 0;
    for (int i = 0; i < 4; i++) {
        memset((char*)self->inner + 0x168 + i * 0xd, 0, 0xd);
    }
    memset((char*)self->inner + 0x19c, 0, 0xd);
    self->inner->f1ac = 0;
    self->inner->f1b0 = 0;
    self->inner->f1b4 = 0;
    self->inner->f1b8 = 0;
    self->inner->f1bc = 0;
    self->inner->f1be = 0;
    self->inner->f1c0 = 0;
    self->inner->f1c4 = 0;
    self->inner->f1cc = 0;
    self->inner->f1d4 = 0;
}