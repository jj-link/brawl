#pragma force_active on
struct Obj {
    unsigned char pad[8];
    int flag;
};

extern "C" void* fn_27_2EBA4C(Obj* p, int idx) {
    int s = p->flag >> 29;
    int t = s + idx;
    if (t >= 3) {
        t -= 3;
    }
    return (unsigned char*)p + t * 12 + 12;
}
