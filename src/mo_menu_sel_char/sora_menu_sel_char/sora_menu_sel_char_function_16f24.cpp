#pragma force_active on
class ScnVt {
public:
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
    virtual void f13(void* p);
};

extern "C" {
extern char lbl_10_data_B20[];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

extern "C" void fn_10_16F24(void* self, unsigned int idx) {
    ScnVt* obj = *(ScnVt**)((char*)self + 0x404);
    void* a = *(void**)((char*)*(void**)((char*)self + idx * 4 + 0xb0) + 0x10);
    obj->f13(a);
    obj = *(ScnVt**)((char*)self + 0x404);
    a = *(void**)((char*)*(void**)((char*)self + idx * 4 + 0xb0) + 0x10);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(obj, a, lbl_10_data_B20);
}
