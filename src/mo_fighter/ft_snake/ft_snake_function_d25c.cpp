#pragma force_active on
extern "C" void fn_27_13604C(void*, void*, unsigned int, void*);

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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void target(unsigned int);
};

extern "C" void fn_122_D25C(void* self, void* a2, unsigned int a3, void* a4) {
    if (a3 == 1) {
        Obj* obj = *(Obj**)((unsigned char*)*(void**)((unsigned char*)*(void**)((unsigned char*)self + 0x60) + 0xd8) + 0x64);
        obj->target(0x1200003d);
    }
    fn_27_13604C(self, a2, a3, a4);
}
