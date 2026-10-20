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

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern "C" {
extern unsigned char lbl_100_bss_194[];
extern unsigned char lbl_100_bss_1A4[];
extern unsigned char lbl_100_bss_1F4[16];
void fn_100_D340(void*, void*);
void fn_100_D880(void*, void*);
void fn_100_DFF0(void*, float, void*, void*);

void fn_100_8A98(int arg0, float arg1, void* arg2, Object* arg3) {
    Modules* modules = arg3->modules;
    Module* status = modules->status;

    switch (status->getStatus()) {
    case 0x113:
        fn_100_D340(lbl_100_bss_194, arg3);
        break;
    case 0x115:
        fn_100_D880(lbl_100_bss_1A4, arg3);
        break;
    case 0x116:
        fn_100_DFF0(lbl_100_bss_1F4, arg1, arg2, arg3);
        break;
    default:
        break;
    }
}
}
