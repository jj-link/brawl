#include <mu/mu_object.h>
#include <string.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_8_data_0[];
extern s8 lbl_8_bss_8;
extern char lbl_8_data_428[];
extern char lbl_8_data_42C[];
extern f32 lbl_8_rodata_0;
void fn_6_1260(void*, const char*);
void fn_1_7A94(void*, void*, int);
}
struct Name { char s[65]; };
struct AnimSlots {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(float);
};
struct Data {
    char pad[0x104];
    char sub[0x60];
    MuObject* object;
    char pad168[0x1d0c-0x168];
    void* field;
};
struct Base { char pad[0x3c]; };
struct Menu : Base {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
    virtual void f28(); virtual void f29(); virtual void f30(int);
    virtual void f31(const char*, int, Data*);
    char pad40[0x16c];
    Data* data;
};
extern "C" void fn_8_1E4(Menu* self) {
    char* base = lbl_8_data_0;
    fn_6_1260(self, base + 0xcc);
    if (lbl_8_bss_8 == 0) {
        base[0x88] = 0;
        strcat(base + 0x88, base + 0xd4);
        lbl_8_bss_8 = 1;
    }
    self->f31(base + 0x88, 1, self->data);
    fn_1_7A94(self->data->field, self->data->sub, 0x19);
    MuObject* obj = self->data->object;
    char* mdl = *(char**)((char*)obj + 8);
    int off = *(int*)(mdl + 0x3c);
    const char* src = off ? mdl + off : 0;
    Name n;
    n.s[0] = 0;
    strcat(n.s, src);
    Name n2 = n;
    strcat(n2.s, lbl_8_data_42C);
    Name n3 = n2;
    sprintf(n3.s + strlen(n3.s), lbl_8_data_428, 0);
    Name n4 = n3;
    obj->changeVisAnimNIf(n4.s);
    AnimSlots* anim = (AnimSlots*)obj->m_modelAnim->m_anmObjVisRes;
    anim->s8(lbl_8_rodata_0);
    self->f30(1);
}