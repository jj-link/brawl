#pragma force_active on
struct IObj {
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
    virtual void vf15(void* p);
};

extern "C" void fn_18_6EE0(void* self_) {
    char* self = (char*)self_;
    IObj* a = *(IObj**)(*(char**)(self + 0x650) + 0x10);
    void* arg = *(void**)(*(char**)(*(char**)(self + 0x64c) + 0x14c) + 0x10);
    a->vf15(arg);
    IObj* b = *(IObj**)(self + 0x654);
    b->vf15(*(void**)(*(char**)(self + 0x650) + 0x10));
}
