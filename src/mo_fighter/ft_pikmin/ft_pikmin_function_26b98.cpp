#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int v4(unsigned int);
};

struct Base {
    char pad[8];
};

struct Motion : Base {
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
    virtual void setStatus(int, int);
};

extern "C" void fn_113_26B98(void*, char* self) {
    Obj* work = *(Obj**)(*(char**)(self + 0xd8) + 0x64);
    if (work->v4(0x10000011) & 0x20) {
        Motion* motion = *(Motion**)(*(char**)(self + 0xd8) + 0x10);
        motion->setStatus(0, 0);
    } else {
        Motion* motion = *(Motion**)(*(char**)(self + 0xd8) + 0x10);
        motion->setStatus(1, 0);
    }
}
