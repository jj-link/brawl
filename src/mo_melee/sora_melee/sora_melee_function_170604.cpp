#pragma force_active on

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(int, unsigned);
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
    virtual unsigned flag(unsigned);
    virtual void v18();
    virtual void clear(unsigned);
};

struct Self {
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
    virtual unsigned test(int);
};

struct Motion {
    char pad[8];
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
    virtual void call(int);
};

struct Modules {
    char pad0[0x10];
    Motion* motion;
    char pad14[0x50];
    Work* work;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" void fn_27_170604(Self* self, soModuleAccesser* a, int b) {
    if (a->modules->work->flag(0x12000002) == 1) {
        int n = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
            a, 0x5a0a, 0);
        a->modules->work->set(n, 0x10000002);
    }

    a->modules->work->clear(0x12000002);

    if (self->test(b) == 1) {
        Motion* motion = a->modules->motion;
        motion->call(0);
    }
}
