#pragma force_active on

class Class_80486468 {
public:
    virtual void fn_80280E3C();
    virtual void fn_80080A64();
    virtual void fn_80281234();
    virtual void fn_802810D0();
    virtual void fn_80281198();
    virtual void fn_80281294();
    virtual void fn_802812A8();
    virtual void fn_802812D0();
    virtual void fn_802812F0();
};

struct Outer {
    char pad[0x8];
    Class_80486468* m_obj;
};

extern "C" {
void fn_802812F0(Outer* o) {
    return o->m_obj->fn_802812F0();
}
}
