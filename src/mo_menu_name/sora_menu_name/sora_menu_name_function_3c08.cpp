#pragma force_active on
struct FnObj {
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
    virtual void vf13(void* arg);
};

extern "C" int fn_16_3C08(unsigned char* self) {
    int count = *(int*)(self + 0x468) - 1;
    *(int*)(self + 0x468) = count;
    if (count > 0) {
        return *(int*)(self + 0x9c);
    }
    FnObj* obj = *(FnObj**)(self + 0x3f8);
    if (obj != 0) {
        obj->vf13(*(void**)(*(unsigned char**)(self + 0x4c) + 0x10));
    } else {
        obj = *(FnObj**)(self + 0xa8);
        obj->vf13(*(void**)(*(unsigned char**)(self + 0x4c) + 0x10));
    }
    return 2;
}
