#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Obj {
    u8 pad[8];
    s32 unk8;
};

extern "C" void* fn_27_D9B60(Obj* p, s32 idx) {
    s32 s = p->unk8 >> 27;
    s32 n = s + idx;
    if (n >= 10) {
        n = n - 10;
    }
    return (char*)p + n * 0x24 + 0xC;
}
