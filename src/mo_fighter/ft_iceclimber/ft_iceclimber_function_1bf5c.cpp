#pragma force_active on
extern "C" {
struct VBase {
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

void* fn_105_1ACB0(void*);

void fn_105_1BF5C(char* self) {
    VBase* obj = (VBase*)fn_105_1ACB0(self + 0x1f1c);
    obj->v6();
}
}
