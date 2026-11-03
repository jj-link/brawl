#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned long);
    virtual void slot13(unsigned long, float);
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
};
struct Modules {
    char pad0[0x44];
    soNullable* stop;
    char pad1[0x1c];
    soNullable* work;
    char pad2[8];
    soNullable* status;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
extern "C" {
extern void* lbl_27_bss_F0;
extern unsigned char lbl_27_bss_7B0C[];
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
float fn_27_192278(void*, unsigned long);
}
inline float clampValue(float v, float lo, float hi) {
    float t = nw4r::math::FSelect(v - lo, v, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}
extern "C" void fn_27_368DAC(void* unused, Accesser* a) {
    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (p != 0) p = fn_27_5BCD0(p);
        lbl_27_bss_F0 = p;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        if (a->modules->stop->slot9() == 0) {
            float x = a->modules->work->slot12(0x11000017);
            float minx = fn_27_192278(a, 0xfa7);
            float maxx = fn_27_192278(a, 0xfa6);
            float y = a->modules->work->slot12(0x11000016);
            float miny = fn_27_192278(a, 0xfa9);
            float maxy = fn_27_192278(a, 0xfa8);
            if (fn_27_30FACC(lbl_27_bss_7B0C, 0, a->modules->status->slot16(), a, 1) != 0x112) {
                x += fn_27_192278(a, 0xfac);
                y += fn_27_192278(a, 0xfad);
            } else if (a->modules->work->slot4(0x20000002) == 1) {
                x -= fn_27_192278(a, 0xfaa);
                y -= fn_27_192278(a, 0xfab);
            }
            a->modules->work->slot13(0x11000017, clampValue(x, minx, maxx));
            a->modules->work->slot13(0x11000016, clampValue(y, miny, maxy));
        }
    }
}
