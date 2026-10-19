#pragma force_active on
extern "C" {
void fn_98_113A8(void* a);
void fn_98_9870(void* owner, void* arg);
}

struct FtVirtualIface {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual int vf16();
};

extern "C" void fn_98_11344(void* a) {
    void* obj = *(void**)((char*)a + 0xd8);
    obj = *(void**)((char*)obj + 0x70);
    if (static_cast<FtVirtualIface*>(obj)->vf16() == 0x11d) {
        fn_98_113A8(a);
        fn_98_9870(a, 0);
    }
}
