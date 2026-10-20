#pragma force_active on
extern "C" void* fn_96_1D7E4(void* owner);

struct VBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void call(int a, float b, int c, int d, float e, float f, int g);
};

extern "C" void fn_96_1D994(void* self, int a, float b, int c, int d, float e, float f) {
    VBase* obj = (VBase*)fn_96_1D7E4(self);
    if (obj != 0) {
        obj->call(a, b, c, d, e, f, *(int*)((char*)self + 8));
    }
}
