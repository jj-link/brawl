#pragma force_active on

extern "C" void* fn_98_14750(void*);
extern "C" void fn_98_17FF4(void*, int, int);

struct Base {
    char pad[8];
};

struct Work : Base {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual int getA();
    virtual int getB();
};

struct Acc {
    char pad[0xbc];
    Work* m_work;
    Work* getWorkManageModule() { return m_work; }
};

struct WeaponLike {
    char pad[0xd8];
    Acc* m_moduleAccesser;
    Acc* getModuleAccesser() { return m_moduleAccesser; }
};

struct Params {
    char pad[0x21];
    signed char kind;
};

extern "C" void fn_98_14154(void* self, Params* params, WeaponLike* weapon) {
    switch (params->kind) {
    case 3: {
        void* article;
        if ((article = fn_98_14750(self)) != 0) {
            Work* work = weapon->getModuleAccesser()->getWorkManageModule();
            fn_98_17FF4(article, work->getB(), work->getA());
        }
        break;
    }
    }
}
