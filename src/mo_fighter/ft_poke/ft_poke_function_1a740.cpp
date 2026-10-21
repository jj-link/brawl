#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct PokePair { unsigned int a, b; };

class PokeIface {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void* s8(int);
    virtual void s7();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual PokePair s15(short*);
};

extern "C" {
extern const char lbl_116_data_6E04[], lbl_116_data_2260[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_116_CB3C(Vec2f*, const Vec2f*);
void fn_27_15FBC8(int);
}

extern "C" void fn_116_1A740(void*, void*, void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(10);
    Vec2f speed;
    short sp8 = 1;
    PokeIface* iface = *(PokeIface**)((unsigned char*)*(void**)((unsigned char*)accesser + 0xD8) + 0x7C);
    PokePair ret = iface->s15(&sp8);
    __memcpy(&speed, &ret, sizeof(speed));
    iface = *(PokeIface**)((unsigned char*)*(void**)((unsigned char*)accesser + 0xD8) + 0x7C);
    void* p = __dynamic_cast(iface->s8(3), 0, lbl_116_data_6E04, lbl_116_data_2260, 1);
    speed.m_x *= soValueAccesser::getConstantFloat(accesser, 0xfa7, 0);
    fn_116_CB3C(reinterpret_cast<Vec2f*>((unsigned char*)p + 8), &speed);
}
