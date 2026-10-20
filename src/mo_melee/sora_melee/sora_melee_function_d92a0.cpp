#pragma force_active on
typedef int s32;

struct Fn27Entry {
    char pad[8];
    s32 field8;
};

extern "C" void* fn_27_D92A0(Fn27Entry* p, s32 n) {
    s32 idx = (p->field8 >> 25) + n;
    if (idx >= 0x2c) {
        idx -= 0x2c;
    }
    return (char*)p + idx * 0x30 + 0xc;
}
