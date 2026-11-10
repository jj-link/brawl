#pragma force_active on

struct Pad8 {
    int a;
    int b;
};

struct Holder : Pad8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* f7(void*, int, int);
};

struct Module {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* f7(void*, int, int);
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
    virtual int getStatus();
    virtual void v18();
    virtual void offFlag(int);
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual Holder* getHolder();
};

struct Setter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(void*, int);
};

struct Modules {
    char pad0[0x64];
    Module* m64;
    char pad68[8];
    Module* m70;
};

struct Fighter {
    char pad0[0xD8];
    Modules* modules;
};

extern "C" void fn_115_18858(void* unused, Fighter* self) {
    Module* m;
    Holder* holder = self->modules->m64->getHolder();
    switch (self->modules->m70->getStatus()) {
    case 1:
        self->modules->m64->offFlag(0x22000000);
        m = self->modules->m64;
        ((Setter*)m)->set(holder->f7(self, 0x5DC1, 0), 0x20000002);
        break;
    case 2:
        m = self->modules->m64;
        ((Setter*)m)->set(holder->f7(self, 0x5DC4, 0), 0x20000000);
        break;
    }
}
