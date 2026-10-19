#pragma force_active on
extern "C" void fn_115_10624(void* unk, void* accesser, unsigned int id);

struct FtObj {
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
    virtual void v14(unsigned int id);
};

extern "C" void fn_115_10304(void* unk, char* accesser) {
    FtObj* obj = *(FtObj**)(*(char**)(accesser + 0xd8) + 0x64);
    obj->v14(0x2100000D);
    fn_115_10624(unk, accesser, 5);
}
