#pragma force_active on
typedef unsigned int u32;

struct Fn77Ctx {
    u32 pad[2];
    int sel;
};

extern "C" void* fn_77_3DA0(Fn77Ctx* p, int idx) {
    int n = (p->sel >> 28) + idx;
    if (n >= 7) {
        n = n - 7;
    }
    return (char*)p + n * 8 + 12;
}
