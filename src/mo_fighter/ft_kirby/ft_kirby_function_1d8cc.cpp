#pragma force_active on
extern "C" void* fn_96_1D7E4(void*);

struct KirbyObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(void*, void*, void*);
};

struct KirbyOwner {
    int pad0;
    int pad4;
    void* field8;
};

extern "C" void fn_96_1D8CC(void* owner, void* arg1, void* arg2) {
    KirbyObj* obj = (KirbyObj*)fn_96_1D7E4(owner);
    if (obj) {
        obj->vf6(arg1, arg2, ((KirbyOwner*)owner)->field8);
    }
}
