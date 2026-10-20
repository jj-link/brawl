#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Inner {
    u8 pad[0x42];
    u8 flag;
};

struct Middle {
    u8 pad0[4];
    Inner* inner;
    u8 pad8[4];
    u8 started;
};

struct Self {
    u8 pad0[0x35C];
    Middle* middle;
};

struct Global {
    u8 pad0[0x174];
    u32 f174;
};

extern void* g_sndSystem;
extern Global* lbl_805A01D8;
extern "C" void playBGM__9sndSystemFiUlb(void*, u32, u32, u32);

extern "C" int fn_1_79B4(Self* self) {
    Middle* middle = self->middle;
    Inner* inner = middle->inner;
    if ((inner->flag >> 6) & 1) {
        if (middle->started == 0) {
            middle->started = 1;
            playBGM__9sndSystemFiUlb(g_sndSystem, 0x270C, 0, 1);
            lbl_805A01D8->f174 = 0x2D;
        }
    }
    return 0;
}
