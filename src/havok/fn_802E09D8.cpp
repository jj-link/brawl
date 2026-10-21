#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Obj {
    unsigned char pad0[0xc];
    s32 field_c;     // 0x0c
    s32 field_10;    // 0x10
    unsigned char pad1[0x38];
    s32 field_4c;    // 0x4c
};

extern "C" s32 fn_802E09D8(void* obj, s32 a1, s32 a2) {
    Obj* o = (Obj*)obj;
    u32 a = (u32)o->field_4c;
    u32 b = (u32)o->field_c;
    s32 c = o->field_10;
    s32 d = c - (s32)a;
    if (a == b) a2++;
    if ((a2 << 7) > d - 0x10)
        return 0;
    return 0x1000000;
}
