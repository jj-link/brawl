#pragma force_active on
typedef unsigned int u32;

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 index);

struct VObj1 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct VObj2 {
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
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(u32, void*);
};

struct Mod {
    char pad0[0x14];
    VObj1* vobj1;
    char pad1[0x48];
    VObj2* vobj2;
};

struct Accesser {
    char pad[0xd8];
    Mod* mod;
};

extern "C" void fn_27_2B314C(void* unused, Accesser* self, int state, float value) {
    if (state == 3) {
        VObj1* v1 = self->mod->vobj1;
        if (v1->v3() == 2) {
            int arg;
            if (value >= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x7f4, 0)) {
                arg = 2;
            } else {
                arg = (value >= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x7f3, 0)) ? 1 : 0;
            }
            self->mod->vobj2->v25(arg, self);
        }
    }
}
