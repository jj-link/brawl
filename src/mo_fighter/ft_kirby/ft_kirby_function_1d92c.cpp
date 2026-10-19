#pragma force_active on
extern "C" void* fn_96_1D7E4(void* owner);

struct VBase {
    virtual void* v0(void*);
    virtual void* v1(void*);
    virtual void* v2(void*);
    virtual void* v3(void*);
    virtual void* v4(void*);
    virtual void* v5(void*);
    virtual void* v6(void*);
    virtual void v7(void*, void*, void*, void*);
};

extern "C" void fn_96_1D92C(void* owner, void* arg1, void* arg2, void* arg3, void* arg4) {
    VBase* obj = (VBase*)fn_96_1D7E4(owner);
    if (obj) {
        obj->v7(arg1, arg2, arg3, arg4);
    }
}
