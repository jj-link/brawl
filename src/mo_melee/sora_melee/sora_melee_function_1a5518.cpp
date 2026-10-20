#pragma force_active on
typedef unsigned int u32;

struct BitS {
    u32 p0;
    u32 p1;
    u32 a : 4;
    u32 f : 4;
    u32 r : 24;
};

extern "C" {
void fn_27_1A5518(BitS* p, u32 v) {
    p->f = v;
}
}
