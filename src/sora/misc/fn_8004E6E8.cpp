typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {

extern long long OSGetTime(void);
extern long long fn_803F1470(long long, long long);

struct Inner {
    u32 pad0[8];
    u64 t;
};

struct Y {
    char pad[0x2d4];
    u32 f2d4;
};

struct Outer {
    struct Inner *p0;
    u32 pad[8];
    struct Y *p24;
};

#pragma force_active on

void *fn_8004E6E8(struct Outer *arg0) {
    u64 t = OSGetTime();
    u32 tick = *(u32 *)0x800000F8;
    u64 r = fn_803F1470(t, (long long)(tick >> 2));
    u64 diff = r - arg0->p0->t;
    u32 v = arg0->p24->f2d4 + (u32)diff;
    if (v >= 0x15752A00) {
        v = 0x157529FF;
    }
    arg0->p24->f2d4 = v;
    arg0->p0->t = r;
    return &arg0->p24->f2d4;
}

}
