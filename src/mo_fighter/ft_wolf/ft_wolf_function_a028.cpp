#pragma force_active on
extern "C" void fn_27_12BAF8(void*, int);

struct FtObjBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

extern "C" void fn_125_A028(void* self, int param)
{
    FtObjBase* obj = *(FtObjBase**)((char*)self + 0x1CC8C);
    obj->v8();
    fn_27_12BAF8(self, param);
}
