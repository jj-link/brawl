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
    virtual void f13(void*);
};

extern "C" {
extern char lbl_10_data_B20[];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

extern "C" void fn_10_16C1C(void* self, int a, int b) {
    if (a == 1 && b != 1) {
        ScnVt* obj = *(ScnVt**)((char*)self + 0x404);
        void* arg = *(void**)((char*)*(void**)((char*)self + 0xcc) + 0x10);
        obj->f13(arg);
        obj = *(ScnVt**)((char*)self + 0x404);
        arg = *(void**)((char*)*(void**)((char*)self + 0xcc) + 0x10);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(obj, arg, lbl_10_data_B20);
    } else {
        ScnVt* obj = *(ScnVt**)((char*)self + 0x404);
        void* arg = *(void**)((char*)*(void**)((char*)self + 0xcc) + 0x10);
        obj->f13(arg);
    }
}
