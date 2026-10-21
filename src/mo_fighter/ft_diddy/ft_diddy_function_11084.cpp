#pragma force_active on
extern "C" void fn_115_11048(void*, int, int, unsigned char);

struct Obj {
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
    virtual unsigned int f12(int);
    virtual void f13();
    virtual void f14(int);
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18(int, void*, int);
};

extern "C" void fn_115_11084(void* unused, void* arg1, int code) {
    unsigned char buf[0x20];
    if (code == 0x120 || code == 0x122) {
        fn_115_11048(buf, 0x23, -1, 1);
        Obj* obj = (Obj*)*(void**)((char*)*(void**)((char*)arg1 + 0xD8) + 0x54);
        obj->f18(0, buf, 0);
    } else {
        Obj* obj = (Obj*)*(void**)((char*)*(void**)((char*)arg1 + 0xD8) + 0x54);
        if (obj->f12(0) == 1) {
            Obj* obj2 = (Obj*)*(void**)((char*)*(void**)((char*)arg1 + 0xD8) + 0x3C);
            obj2->f14(0);
        }
    }
}
