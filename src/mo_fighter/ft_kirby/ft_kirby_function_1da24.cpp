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
    virtual void* vf9(void* arg);
};

struct KirbyOwner {
    int pad0;
    int pad4;
    void* field8;
};

extern "C" void* fn_96_1DA24(void* owner) {
    KirbyObj* obj = (KirbyObj*)fn_96_1D7E4(owner);
    if (obj) {
        return obj->vf9(((KirbyOwner*)owner)->field8);
    }
    return 0;
}
