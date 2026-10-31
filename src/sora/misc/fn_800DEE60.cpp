#include <gf/gf_model.h>

#pragma force_active on

extern "C" void fn_800B753C(void*, float);
extern const float lbl_805A2368;
extern const float lbl_805A2374;

class Target {
public:
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
    virtual void s11(void*, void*);
    virtual void s12();
    virtual void s13(void*);

    char pad[0xE0];
    void* field_E4;
};

extern "C" void fn_800DEE60(void* arg0) {
    char* base = (char*)arg0;
    int i;
    void* anim = *(void**)(base + 0x5C);

    ((gfModelAnimation*)*(void**)((char*)anim + 0x14))->setUpdateRate(lbl_805A2368);
    fn_800B753C(anim, lbl_805A2374);

    char* p = base + 0x34;
    for (i = 0xD; i < 0x18; i++, p += 4) {
        void* entry = *(void**)(p + 0x10);
        if (entry != 0) {
            Target* target = *(Target**)(base + 0x8);
            target->s13(*(void**)((char*)entry + 0x10));
        }
    }

    Target* target = *(Target**)(base + 0x8);
    target->s11(target->field_E4, *(void**)((char*)anim + 0x10));
}
