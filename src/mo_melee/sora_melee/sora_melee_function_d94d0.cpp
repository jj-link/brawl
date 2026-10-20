#pragma force_active on
struct Obj {
    unsigned char pad[8];
    int field8;
};

extern "C" {
void* fn_27_D94D0(Obj* p, int idx)
{
    int n = (p->field8 >> 26) + idx;
    if (n >= 26) {
        n -= 26;
    }
    return (char*)p + n * 0x30 + 0xc;
}
}
