#include <types.h>
#pragma force_active on

struct IValueMod {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getValue(u32 id);
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual float getFloat(u32 id);
};

struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
void* fn_41_473DC(void* acc, s32 v);
void fn_41_47470(void* out, void* p, void* acc);
void fn_41_47544(u8* out, void* p);
void fn_41_47A2C(void* p, void* acc, u32 flag);
void fn_41_477EC(u32 id, void* p, void* acc, u32 flag, u32 n);
void fn_41_47C64(void* p, void* acc, void* buf, Vec3f* vec, u32 zero);
void fn_41_47D8C(void* out, u32 zero, void* self, void* p, void* acc);
extern u8 lbl_41_bss_504[];
extern float lbl_41_rodata_1158;
}

static IValueMod* getValueMod(void* acc) {
    void* p = *(void**)((u8*)acc + 0xd8);
    return *(IValueMod**)((u8*)p + 0x64);
}

extern "C" s32 fn_41_5F128(void* self, void* acc) {
    u8 buf[0x10];
    u8 flag;
    Vec3f vec;
    void* p = fn_41_473DC(acc, getValueMod(acc)->getValue(0x10000007));
    fn_41_47470(buf, p, acc);
    flag = 0;
    fn_41_47544(&flag, p);
    u32 c = *(u32*)((u8*)p + 0xc);
    if (c == 2 || c == 4) {
        fn_41_47A2C(p, acc, 1);
    } else {
        u32 id = *(u32*)(lbl_41_bss_504 + 8);
        if (id == 0x1a || id == 0x24 || id == 0x31 || id == 0x39) {
            fn_41_477EC(id, p, acc, 1, 0);
        } else if (id == 0x15) {
            fn_41_477EC(id, p, acc, 1, 4);
        }
        if (id == 0x18 || id == 0x22 || id == 0x2f) {
            fn_41_477EC(id, p, acc, 1, 0);
        } else if (id == 0x1f) {
            fn_41_477EC(id, p, acc, 1, 5);
        } else if (id == 0x10) {
            vec.x = getValueMod(acc)->getFloat(0x1100000A);
            vec.y = getValueMod(acc)->getFloat(0x1100000B);
            vec.z = lbl_41_rodata_1158;
            fn_41_47C64(p, acc, buf, &vec, 0);
        }
    }
    fn_41_47D8C(buf, 0, self, p, acc);
    return 0;
}
