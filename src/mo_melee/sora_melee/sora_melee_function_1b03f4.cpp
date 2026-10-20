#pragma force_active on
struct Obj {
    char pad[0x8];
    int field8;
};

extern "C" {
char* fn_27_1B03F4(Obj* p, int idx) {
    int i = (p->field8 >> 27) + idx;
    i = (i >= 8) ? i - 8 : i;
    return (char*)p + i * 0x90 + 0xc;
}
}
