#pragma force_active on
struct Module {
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
    virtual int getStatus();
};

struct Modules {
    char pad[0x70];
    Module* status;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Accesser* accesser;
};

extern "C" {
extern unsigned char lbl_100_bss_1F4[16];
void fn_100_E1A0(void*, unsigned int, Accesser*);
void fn_27_135468(Object*, unsigned int);

void fn_100_8B54(Object* self, unsigned int flags) {
    Accesser* accesser = self->accesser;
    Module* status = accesser->modules->status;

    switch (status->getStatus()) {
    case 0x116:
        fn_100_E1A0(lbl_100_bss_1F4, flags, accesser);
        break;
    default:
        fn_27_135468(self, flags);
        break;
    }
}
}
