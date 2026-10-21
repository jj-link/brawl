#pragma force_active on
extern "C" void fn_27_1DB0E8(void*);
extern "C" void fn_27_1DB174(void*, float, int, float);
extern "C" void fn_107_1F764(void*, void*, float, unsigned char);
extern "C" const float lbl_107_rodata_138;

struct VObj {
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
    virtual void v13();
    virtual void v14();
    virtual void call(int, void*);
};

extern "C" void fn_107_1F77C(
    void* self, float f, void* p2, void* p3, void* p4,
    unsigned char* obj)
{
    char tmp[8];
    fn_27_1DB0E8(self);
    fn_107_1F764(tmp, (void*)0x839, f, 1);
    VObj* b = *(VObj**)(*(char**)((char*)obj + 0xd8) + 0x54);
    b->call(3, tmp);
    fn_27_1DB174(self, f, 1, lbl_107_rodata_138);
}
