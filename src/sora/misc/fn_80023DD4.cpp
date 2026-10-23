#pragma force_active on

typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef unsigned char u8;

extern "C" u64 OSGetTime(void);
extern "C" u8* lbl_8059FFFC;

struct Ctx {
    u8 pad_00[0x40];
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4C;
    s32 f50;
    s32 f54;
    u8 pad_58[0x70 - 0x58];
    void (*f70)(void);
};

extern "C" void fn_80023DD4(s32 arg0) {
    Ctx* p = (Ctx*)lbl_8059FFFC;
    if ((arg0 & 0xF000) == 0xF000) {
        switch (arg0) {
        case 0xFFE0: {
            u64 t = OSGetTime();
            p->f4C = (u32)t;
            p->f48 = (u32)(t >> 32);
            u64 prev = ((u64)p->f40 << 32) | p->f44;
            u64 d = t - prev;
            p->f54 = (s32)(u32)d;
            p->f50 = (s32)(u32)(d >> 32);
            break;
        }
        case 0xFFF0:
        case 0xF000:
            break;
        }
    } else {
        if (p->f70 != 0) {
            p->f70();
        }
    }
}
