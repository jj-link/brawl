#include <types.h>
#include <string.h>
#pragma force_active on

struct Item {
    u32 kind;
    char name[0x28];
};

struct Menu {
    char pad_00[0x44];
    u32 f44;
    u32 f48;
    char pad_4c[0xB4];
    void* f100;
    Item items[9];
    char pad_290[4];
    void* f294;
    void* f298;
    void* f29c;
    void* f2a0;
    char pad_2a4[0x5C];
    u32 f300;
    char pad_304[0x10];
    u32 f314;
    char pad_318[0x20];
    u32 f338;
    u32 f33c;
};

extern "C" {
void fn_3_DBD4(void*, u32);
int fn_800B5854(void*, int, int, int, int);
void fn_800B92D8(void*, u32, char*, u32);
void playBGM__9sndSystemFiUlb(void*, s32, u32, u32);
void setFrameTex__8MuObjectFf(void*, f32);
extern const f32 lbl_3_rodata_84B0;
extern void* g_sndSystem;
}

extern "C" void fn_3_D9A8(Menu* self) {
    if (self->f314 == 0xB) {
        char* e;
        u32 count;
        u32 k;
        self->f48 = 5;
        self->f338 = self->f300;
        self->f33c = self->f300;
        e = (char*)self;
        for (k = 0; k < (count = self->f300); k++) {
            if (*(int*)(e + 0x104) != 2) {
                self->f338 = k;
                self->f33c = k;
            }
            e += 0x2c;
        }
        if (self->f338 == count) {
            self->f338 = 0;
            self->f33c = 0;
        }
        fn_3_DBD4(self, self->f338);
        playBGM__9sndSystemFiUlb(g_sndSystem, 0x2703, 0, 1);
        return;
    }

    self->f48 = 4;
    self->f44 = 5;
    fn_800B5854(self->f294, 1, 1, 1, 0);
    fn_800B5854(self->f298, 1, 0x11, 1, 0);
    fn_800B5854(self->f29c, 1, 0x13, 1, 0);
    fn_800B5854(self->f29c, 1, 4, 0, 0);
    setFrameTex__8MuObjectFf(self->f29c, lbl_3_rodata_84B0);
    self->f338 = self->f300;
    self->f33c = self->f300;
    char* e = (char*)self;
    char* q = (char*)self;
    u32 offset;
    u32 i = 0;
    while (i < self->f300) {
        if (*(int*)(e + 0x104) == 2) {
            fn_800B5854(*(void**)(q + 0x2a0), 8, 0x11, 1, 0);
        } else {
            fn_800B5854(*(void**)(q + 0x2a0), 8, 0x11, 0, 0);
            self->f338 = i;
            self->f33c = i;
        }
        e += 0x2c;
        q += 4;
        i++;
    }
    if (self->f338 == self->f300) {
        self->f338 = 0;
        self->f33c = 0;
        fn_800B5854(self->f2a0, 8, 0x11, 0, 0);
    }
    offset = self->f338 * 0x2c;
    fn_800B92D8(self->f100, 0, ((Item*)((char*)self->items + offset))->name,
                strlen((char*)self + offset + 0x108));
}
