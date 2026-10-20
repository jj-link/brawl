#pragma force_active on
typedef unsigned int u32;

class Base {
public:
    u32 m_pad;
};

class IObj : public Base {
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
    virtual int f10(void*, void*);
};

extern "C" IObj* fn_27_8CE44(void*);

extern "C" {
int fn_27_150B34(char* self, void* a, void* b) {
    IObj* obj = fn_27_8CE44(*(void**)(*(char**)(self + 0x2c) + 8));
    return obj->f10(b, a);
}
}
