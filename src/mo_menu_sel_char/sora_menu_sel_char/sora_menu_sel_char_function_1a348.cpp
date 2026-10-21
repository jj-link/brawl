#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

class IObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11(void*, void*);
    virtual void f12();
    virtual void f13(void*);
};

extern "C" void fn_10_1A348(void* arg0, u32 arg1, s32 arg2) {
    u8* self = (u8*)arg0;
    s8 var_r31;

    if (arg1 <= 3U && *(s32*)(*(u8**)(self + 0x9c) + 0x1dc) >= 0) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    IObj* obj = *(IObj**)(self + 0x40);
    obj->f13(*(void**)(self + 0x44));
    if (var_r31 != 0 && *(u8*)(self + 0xdc) == 0) {
        obj = *(IObj**)(self + 0x40);
        obj->f11(*(void**)((u8*)obj + 0xe4), *(void**)(self + 0x44));
    }
    *(s8*)(self + 0xd0) = var_r31;
    *(u32*)(self + 0xa4) = arg1;
    *(s32*)(self + 0xa8) = arg2;
}
