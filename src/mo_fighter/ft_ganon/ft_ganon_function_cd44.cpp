#pragma force_active on
extern "C" void fn_109_CA24(void*, int, int, int);

struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16(int, void*, int);
};

extern "C" void fn_109_CD44(void*, void* arg1) {
    unsigned char event[0x20];
    fn_109_CA24(event, 0x21, 0x1B3, 1);
    void* module = *(void**)((char*)arg1 + 0xD8);
    Obj* obj = (Obj*)*(void**)((char*)module + 0x54);
    obj->f16(0, event, 0);
}
