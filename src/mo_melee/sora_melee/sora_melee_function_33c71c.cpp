#include <types.h>
#include <mt/mt_vector.h>

#pragma force_active on

struct Obj2 {
    virtual void s0();
    virtual void s1();
    virtual int s2();
};

struct Obj26 {
    virtual void s0();
    virtual void s1();
    virtual Obj2* s2();
    virtual void s3();
    virtual Vec3f s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual float s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual float s22();
};

struct Obj31a {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
};

struct Obj31b {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3(void* a, void* b);
};

struct Obj17 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual int s17(int a, void* b);
};

struct Table { float values[9]; };
extern "C" {
extern const Table lbl_27_rodata_7710;
float fn_27_192278(void*, unsigned long);
void fn_27_34080C(void*, int, int, int, Vec3f*, int, int, float);
int randi__Fl(long);
extern const float lbl_27_rodata_7734;
}

extern "C" int fn_27_33C71C(void* unused, void* obj, void* acc, int arg3) {
    Table table = lbl_27_rodata_7710;
    Obj26* a26;
    void* a31;
    char* m;
    m = *(char**)((char*)acc + 0xd8);
    a26 = *(Obj26**)(m + 0xc);
    a31 = *(void**)(m + 0x14);
    Vec3f pos = a26->s4();
    float f31 = a26->s22();
    float f30 = a26->s9();
    float f26 = fn_27_192278(acc, 0xfa0);
    float f27 = fn_27_192278(acc, 0xfa1);
    float f28 = fn_27_192278(acc, 0xfa2);
    float f29 = fn_27_192278(acc, 0xfa3);
    if (((Obj31a*)a31)->s3() == 0) {
        pos.m_x += f31 * (f26 * f30);
        int r = randi__Fl(9);
        pos.m_y += f31 * (f27 + table.values[r]);
    } else {
        pos.m_x += f31 * (f28 * f30);
        int r = randi__Fl(9);
        float value = table.values[r];
        pos.m_y += f31 * (f29 + lbl_27_rodata_7734 * value);
    }
    int r25v = ((Obj17*)(*(void**)(*(char**)((char*)acc + 0xd8) + 0x64)))->s17(0x22000012, *(void**)((char*)acc + 0xd8));
    Obj26* a26b = *(Obj26**)(*(char**)((char*)acc + 0xd8) + 0x18);
    void* o8 = *(void**)((char*)acc + 8);
    int r27 = *(int*)((char*)o8 + 0x28);
    int r29v = ((Obj31b*)a31)->s3(o8, *(void**)((char*)acc + 0xd8));
    Obj2* x = a26b->s2();
    int chain = x->s2();
    fn_27_34080C(obj, r27, arg3, chain, &pos, r25v, r29v, f30);
    return 0;
}
