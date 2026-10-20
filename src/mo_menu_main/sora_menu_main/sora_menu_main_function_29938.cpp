#pragma force_active on
class IFace {
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
    virtual void v15(void* p);
};

extern "C" void fn_800B8EDC(void*, void*);
extern "C" void free__13gfHeapManagerFPv(void*);

extern "C" void fn_2_29938(char* self) {
    IFace* a = *(IFace**)(self + 0x654);
    a->v15(*(void**)(self + 0x68c));
    IFace* b = *(IFace**)(self + 0x654);
    b->v15(*(void**)(self + 0x690));
    fn_800B8EDC(*(void**)(self + 0x678), *(void**)(self + 0x680));
    fn_800B8EDC(*(void**)(self + 0x678), *(void**)(self + 0x684));
    free__13gfHeapManagerFPv(*(void**)(self + 0x6a4));
}
