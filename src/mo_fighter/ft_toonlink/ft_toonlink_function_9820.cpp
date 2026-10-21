#pragma force_active on

struct StatusModule {
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
    virtual int get(int);
};

struct WorkModule {
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
    virtual unsigned int isFlag(unsigned int);
};

struct VisibilityModule {
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
    virtual void setStatusDefault(unsigned int, int, unsigned int);
};

struct Modules {
    unsigned char padding0[0x20];
    StatusModule* status;
    VisibilityModule* visibility;
    unsigned char padding1[0x3C];
    WorkModule* work;
};

struct soModuleAccesser {
    unsigned char padding[0xD8];
    Modules* modules;
};

extern "C" void fn_27_135EE8(void*, int, soModuleAccesser*);

extern "C" void fn_121_9820(void* self, int arg, soModuleAccesser* accesser) {
    StatusModule* status = accesser->modules->status;
    int previous = status->get(0);
    fn_27_135EE8(self, arg, accesser);

    if (*((unsigned char*)self + 0x1A384) == 1) {
        WorkModule* work = accesser->modules->work;
        if (work->isFlag(0x12000035) == 1U) {
            if (previous == 0) {
                VisibilityModule* visibility = accesser->modules->visibility;
                visibility->setStatusDefault(0, 0, true);
            } else {
                VisibilityModule* visibility = accesser->modules->visibility;
                visibility->setStatusDefault(0, 1, true);
            }
        }
    }
}
