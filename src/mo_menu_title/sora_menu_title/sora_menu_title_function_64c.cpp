#pragma force_active on
class Base {
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
    virtual void f13(void* arg);
};

class Holder {
public:
    char pad[0x48];
    Base* obj;
};

extern "C" void fn_24_64C(char* self) {
    Holder* a = *(Holder**)(self + 0x1c4);
    Holder* b = *(Holder**)(self + 0x1c8);
    a->obj->f13(*(void**)((char*)b + 0xc));
    a = *(Holder**)(self + 0x1c4);
    b = *(Holder**)(self + 0x1cc);
    a->obj->f13(*(void**)((char*)b + 0xc));
}
