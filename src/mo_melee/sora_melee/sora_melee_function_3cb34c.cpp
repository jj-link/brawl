#pragma force_active on
extern "C" void fn_27_1DACB8(void* fighter);
extern "C" const float lbl_27_rodata_80F0;

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(float f, unsigned int u);
};

extern "C" void fn_27_3CB34C(void* fighter) {
    Obj* o = (Obj*)*(void**)((char*)*(void**)((char*)*(void**)((char*)fighter + 0x60) + 0xd8) + 0x64);
    o->v13(lbl_27_rodata_80F0, 0x11000001);
    fn_27_1DACB8(fighter);
}
