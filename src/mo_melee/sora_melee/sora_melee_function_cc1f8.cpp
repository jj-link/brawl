#pragma force_active on
class fn_27_Base {
public:
    virtual bool fn_27_v0();
    virtual bool fn_27_v1();
    virtual bool fn_27_v2();
    virtual bool fn_27_v3();
    virtual bool fn_27_v4();
    virtual bool fn_27_v5();
};

extern "C" bool fn_27_CC1F8(fn_27_Base* p) {
    return !p->fn_27_v3();
}
