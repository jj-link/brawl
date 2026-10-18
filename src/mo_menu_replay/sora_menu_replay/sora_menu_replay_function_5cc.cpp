#pragma force_active on
class Obj {
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
    virtual void f11(int, int);
};

extern "C" void fn_7_5CC(char* self, int arg) {
    char* p1 = *(char**)(self + 0x1ac);
    char* p2 = *(char**)(p1 + 0x1d0c);
    char* p3 = *(char**)(p2 + 0x35c);
    char* p4 = *(char**)p3;
    Obj* obj;
    if (*(unsigned char*)(p4 + 0x1a4) != 0) {
        obj = *(Obj**)(p4 + 0x48);
    } else {
        obj = 0;
    }
    obj->f11(*(int*)((char*)obj + 0xe4), arg);
}
