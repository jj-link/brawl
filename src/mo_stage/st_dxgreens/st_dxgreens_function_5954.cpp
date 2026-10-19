#pragma force_active on
struct Obj {
    int pad[2];
    int f8;
};

extern "C" char* fn_79_5954(Obj* p, int n) {
    int r = p->f8 >> 26;
    int t = r + n;
    if (t >= 30) {
        t -= 30;
    }
    return (char*)p + t * 0x78 + 0xc;
}
