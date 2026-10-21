#pragma force_active on

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
    virtual float v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual unsigned int v17(unsigned int);
    virtual void v18(unsigned int);
};

extern "C" {
float fn_93_A600(void* accesser);
void fn_93_13A38(void* self, float facing, float f, unsigned int id);
}

extern "C" int fn_93_A548(void* self, void* accesser) {
    unsigned int id;
    unsigned char* acc = (unsigned char*)accesser;
    unsigned char* mod = *(unsigned char**)(acc + 0xd8);
    Obj* posture = *(Obj**)(mod + 0xc);
    Obj* work = *(Obj**)(mod + 0x64);
    id = work->v17(0x22000011);
    float f = fn_93_A600(accesser);
    fn_93_13A38(self, posture->v9(), f, id);
    unsigned char* mod2 = *(unsigned char**)(acc + 0xd8);
    Obj* work2 = *(Obj**)(mod2 + 0x64);
    work2->v18(0x1200003d);
    return 1;
}
