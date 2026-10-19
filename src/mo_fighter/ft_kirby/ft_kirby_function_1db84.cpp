#pragma force_active on
extern "C" void* fn_96_1D7E4(void*);

struct KirbyObj {
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
    virtual int vf16(int arg, void* field);
};

struct KirbyOwner {
    int pad0;
    int pad4;
    void* field8;
};

extern "C" int fn_96_1DB84(void* owner, int arg) {
    KirbyObj* obj = (KirbyObj*)fn_96_1D7E4(owner);
    if (obj) {
        return obj->vf16(arg, ((KirbyOwner*)owner)->field8);
    }
    return 0;
}
