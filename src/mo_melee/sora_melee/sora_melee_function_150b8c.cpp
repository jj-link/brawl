#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

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
    virtual void f10();
    virtual void f11(u8);
};

extern "C" IObj* fn_27_8CE44(void*);

extern "C" void fn_27_150B8C(char* self, u32 mode) {
    u8 flag = 0;
    if (mode == 1)
        flag |= 1;

    IObj* obj = fn_27_8CE44(*(void**)(*(char**)(self + 0x2c) + 8));
    if (flag)
        obj->f11(flag);
    else
        obj->f9();
}
