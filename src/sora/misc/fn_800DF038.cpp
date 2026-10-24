#pragma force_active on

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
};

extern "C" void setUpdateRate__16gfModelAnimationFf(void*, float);
extern "C" void fn_800B753C(void*, float);
extern const float lbl_805A2368;
extern const float lbl_805A2374;

extern "C" void fn_800DF038(void* arg0) {
    float rate = lbl_805A2368;
    int i;
    char* model = (char*)*(void**)((char*)arg0 + 0x64);
    setUpdateRate__16gfModelAnimationFf(*(void**)(model + 0x14), rate);
    fn_800B753C(model, lbl_805A2374);

    void** p = (void**)((char*)arg0 + 0x34);
    for (i = 0xD; i < 0x18; i++, p++) {
        if (p[4] != 0) {
            Target* t = *(Target**)((char*)arg0 + 0x8);
            t->s13(((void**)p[4])[4]);
        }
    }

    Target* t = *(Target**)((char*)arg0 + 0x8);
    t->s11(*(void**)((char*)t + 0xE4), *(void**)(model + 0x10));
}
