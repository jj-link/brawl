#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u32 fn_27_6F30C(void*);

class VA {
public:
    virtual void f0();
    virtual u8* f1();
    virtual void f2();
    virtual void f3();
};

class VB {
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
    virtual void f11();
};

extern "C" void fn_27_6C79C(u8* p) {
    u8* a = *(u8**)(p + 0x48);
    u8* x = (u8*)fn_27_6F30C(((VA*)a)->f1() + 0x1c);
    u8* y = *(u8**)(x + 0x44);
    u8* z = *(u8**)(y + 0xd8);
    u8* w = *(u8**)(z + 0xc);
    ((VB*)w)->f9();
}
