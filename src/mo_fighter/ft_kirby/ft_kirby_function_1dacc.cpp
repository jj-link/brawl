#pragma force_active on
extern "C" {
void* fn_96_1D7E4(void* owner);
}

struct VBase {
    virtual void* v0(void*);
    virtual void* v1(void*);
    virtual void* v2(void*);
    virtual void* v3(void*);
    virtual void* v4(void*);
    virtual void* v5(void*);
    virtual void* v6(void*);
    virtual void* v7(void*);
    virtual void* v8(void*);
    virtual void* v9(void*);
    virtual void* v10(void*);
    virtual void* v11(void*);
    virtual void* v12(void*);
    virtual void* v13(void*);
};

extern "C" void* fn_96_1DACC(void* owner) {
    VBase* obj = (VBase*)fn_96_1D7E4(owner);
    if (obj) {
        return obj->v11(((void**)owner)[2]);
    }
    return 0;
}
