#pragma force_active on
extern "C" void fn_27_5A78(void*);
extern "C" void* fn_123_8DCC(int);

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v6(void*);
    virtual void v5();
    virtual void v6b();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v18();
};

extern "C" void fn_123_8D60(void* self) {
    void* p = *(void**)((char*)self + 0x60);
    p = *(void**)((char*)p + 0xD8);
    p = *(void**)((char*)p + 0x70);
    int r = ((VObj*)p)->v18();
    if (r == 0x112) {
        VObj* o = (VObj*)fn_123_8DCC(r);
        o->v6(*(void**)((char*)self + 0x60));
    }
    fn_27_5A78(self);
}
