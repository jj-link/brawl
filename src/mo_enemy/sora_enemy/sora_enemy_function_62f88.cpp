#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

struct Module {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void set(s32, s32);
};

struct ModuleList {
    unsigned char padding[0x20];
    Module* module;
};

struct soModuleAccesser {
    unsigned char padding[0xD8];
    ModuleList* modules;
};

extern "C" void fn_41_A2A4(void*, s32, u32, u32, soModuleAccesser*);
extern "C" unsigned char* lbl_27_bss_5668;

extern "C" void fn_41_62F88(
    void* self, s32 p1, u32 p2, u32 p3, soModuleAccesser* acc
) {
    fn_41_A2A4(self, p1, p2, p3, acc);
    if (lbl_27_bss_5668[0x19F] == 1) {
        Module* module = acc->modules->module;
        module->set(2, 0);
    }
}
