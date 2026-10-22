#pragma force_active on
typedef int s32;

extern "C" {
void fn_801C05C0(void*, void*, s32);
void* fn_801C07AC(void*);
}

struct Pair {
    s32 x;
    s32 y;
};

struct Blk {
    Pair p0;
    Pair p1;
    Pair p2;
};

extern "C" void fn_8007757C(unsigned char* self, float v) {
    if (self[0x6EF]) {
        Blk blk;
        blk = *(Blk*)fn_801C07AC(self + 0x728);
        *(float*)&blk.p1.x = v;
        fn_801C05C0(self + 0x728, &blk, blk.p2.x);
    }
}
