#pragma force_active on
extern "C" int fn_800B63B8(void*);

class VBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(void* a);
};

extern "C" int fn_800DE94C(void* self) {
    void* obj = *(void**)((unsigned char*)self + 0x48);
    if (fn_800B63B8(obj) == 0) {
        return 3;
    }
    VBase* p8 = *(VBase**)((unsigned char*)self + 0x8);
    p8->v13(*(void**)((unsigned char*)obj + 0x10));
    return 0;
}
