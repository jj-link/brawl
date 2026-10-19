#pragma force_active on
struct UnkObjectA {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual int v4C(int);
    virtual void v50();
    virtual void v54(int);
};

struct UnkBlock {
    char pad[0x64];
    UnkObjectA* m64;
};

struct UnkFighter {
    char pad[0xD8];
    UnkBlock* mD8;
};

extern "C" void fn_102_D75C(void* arg);

extern "C" void fn_102_D87C(void*, void* arg) {
    UnkFighter* f = (UnkFighter*)arg;
    UnkObjectA* b = f->mD8->m64;
    if (b->v4C(0x1200003d) != 0) {
        fn_102_D75C(arg);
        b->v54(0x1200003d);
    }
}
