#pragma force_active on

struct Class50 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int, int, int);
};

struct Class5c {
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(int, int, int, int);
};

struct Class88 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int, int, float*, int, int);
};

struct Module {
    char pad0[0x50];
    Class50* f50;
    char pad54[8];
    Class5c* f5c;
    char pad60[0x28];
    Class88* f88;
};

struct soModuleAccesser {
    char pad0[0xd8];
    Module* f0xd8;
};

struct Vec3 {
    float x, y, z;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long, void*);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);

extern const float lbl_27_rodata_26B0;

void fn_27_195F7C(soModuleAccesser* self, int arg1) {
    Vec3 v;
    v.x = lbl_27_rodata_26B0;
    v.y = lbl_27_rodata_26B0;
    v.z = lbl_27_rodata_26B0;
    Class88* c88 = self->f0xd8->f88;
    getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xbe9, 0, self->f0xd8);
    c88->v6(0x4e, arg1, &v.x, 0, -1);

    int result = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x59e8, 0);
    switch (result) {
        case 0:
            self->f0xd8->f50->v5(0xba, 0, 0, 0);
            break;
        case 1:
            self->f0xd8->f50->v5(0xbb, 0, 0, 0);
            break;
        case 2:
            self->f0xd8->f50->v5(0xbc, 0, 0, 0);
            break;
    }

    getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x59ea, 0);
    switch (result) {
        case 0:
        case 1:
            self->f0xd8->f5c->v55(0x17, 0, 0, -1);
            break;
        case 2:
            self->f0xd8->f5c->v55(4, 0, 0, -1);
            break;
        case 3:
            self->f0xd8->f5c->v55(0xe, 0, 0, -1);
            break;
    }
}
}
