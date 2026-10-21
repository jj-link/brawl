#pragma force_active on
class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
};

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(int);
    char pad[12];
    Sub m_10;
};

extern "C" void fn_27_714A4(short* out, const void* arg1);

extern "C" void fn_27_D863C(short* out, Obj* obj, int arg2) {
    if (obj->v6(arg2) == 0) {
        *out = 0;
        return;
    }
    if (obj->m_10.v4() != 1U && arg2 >= 0) {
        obj->m_10.v13();
    }
    fn_27_714A4(out, static_cast<const char*>(static_cast<const void*>(obj)) + arg2 * 0x18 + 0x1C);
}
