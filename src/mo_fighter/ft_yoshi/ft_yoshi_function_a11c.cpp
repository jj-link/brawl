#pragma force_active on
extern "C" void fn_27_12BAF8(void* object, int param);

struct Obj {
    virtual void f0(int, unsigned int) = 0;
    virtual void f1(int, unsigned int) = 0;
    virtual void f2(int, unsigned int) = 0;
    virtual void f3(int, unsigned int) = 0;
    virtual void f4(int, unsigned int) = 0;
    virtual void f5(int, unsigned int) = 0;
    virtual void f6(int, unsigned int) = 0;
    virtual void f7(int, unsigned int) = 0;
    virtual void f8(int, unsigned int) = 0;
    virtual void f9(int, unsigned int) = 0;
    virtual void f10(int, unsigned int) = 0;
    virtual void f11(int, unsigned int) = 0;
    virtual void f12(int, unsigned int) = 0;
    virtual void f13(float, unsigned int) = 0;
    virtual void f14(int, unsigned int) = 0;
    virtual void f15(int, unsigned int) = 0;
};

extern "C" void fn_95_A11C(void* self, int param) {
    fn_27_12BAF8(self, param);
    char* a = *(char**)((char*)self + 0x60);
    char* b = *(char**)(a + 0xd8);
    Obj* obj = *(Obj**)(b + 0x64);
    obj->f5(0, 0x10000040);
    obj->f13(*(float*)(*(char**)(*(char**)((char*)self + 0x22284) + 0x80) + 0x8), 0x11000013);
}
