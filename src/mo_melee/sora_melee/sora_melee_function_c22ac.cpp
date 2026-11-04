#include <types.h>
#pragma force_active on

extern "C" {

struct FnC1AB8Obj {
    u8 pad0[0x8];
    f32 f8;
    f32 fc;
    f32 f10;
    u8 pad14[8];
    s16 s1c;
};

void fn_27_C1AB8(FnC1AB8Obj* p);

class VtblObj {
public:
    virtual void m00();
    virtual void m01();
    virtual void m02();
    virtual void m03();
    virtual void m04();
    virtual void m05();
    virtual void m06();
    virtual void m07();
    virtual void m08();
    virtual void m09();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual u32 m23(s16);
    virtual u32 m24(s16);
};

void fn_27_C22AC(void* self) {
    u8* p = static_cast<u8*>(self);
    void* x = *(void**)(p + 0x18);
    void* y = *(void**)((u8*)x + 0xD8);
    VtblObj* v = *(VtblObj**)((u8*)y + 0x90);
    if (v->m23(*(s16*)(p + 0x44)) == 1) {
        void* x2 = *(void**)(p + 0x18);
        void* y2 = *(void**)((u8*)x2 + 0xD8);
        VtblObj* v2 = *(VtblObj**)((u8*)y2 + 0x90);
        *(u32*)(p + 0x1C) = v2->m24(*(s16*)(p + 0x44));
    } else {
        *(u32*)(p + 0x1C) = 0;
    }
    p[0x47] = 0;
    *(s8*)(p + 0x46) = -1;
    fn_27_C1AB8(reinterpret_cast<FnC1AB8Obj*>(p + 0x1C));
    p[0x4A] = 0;
}

}