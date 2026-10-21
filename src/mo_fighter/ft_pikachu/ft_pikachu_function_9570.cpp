#pragma force_active on
extern "C" {
extern signed char lbl_98_bss_214;
extern char lbl_98_bss_218[8];
extern char lbl_98_bss_200[12];
void fn_27_3244C4(void*);
void* fn_27_3244D4(void*, int);
void* __register_global_object(void*, void*, void*);
void* fn_27_324660(void*, void*, void*, unsigned int);
}

struct ResourceModule {
    unsigned int pad[2];
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void* getAccesser();
};

struct ResourceAccesser {
    virtual void unused00();
    virtual void unused01();
    virtual void unused02();
    virtual void unused03();
    virtual void unused04();
    virtual void unused05();
    virtual void unused06();
    virtual void unused07();
    virtual void unused08();
    virtual void unused09();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual unsigned int getId();
};

extern "C" void fn_98_9570(void* a, void* b) {
    if (lbl_98_bss_214 == 0) {
        fn_27_3244C4(lbl_98_bss_218);
        __register_global_object(lbl_98_bss_218, (void*)fn_27_3244D4, lbl_98_bss_200);
        lbl_98_bss_214 = 1;
    }

    void* module = *(void**)((char*)b + 0xD8);
    module = *(void**)module;
    ResourceAccesser* accesser =
        static_cast<ResourceAccesser*>(static_cast<ResourceModule*>(module)->getAccesser());
    fn_27_324660(lbl_98_bss_218, a, b, accesser->getId());
}
