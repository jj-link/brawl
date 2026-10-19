#pragma force_active on
class soBaseFn27 {
public:
    virtual ~soBaseFn27();
    virtual void v0();
    virtual void v1();
    virtual bool v2();
};

extern "C" bool fn_27_1069AC(soBaseFn27* p) {
    return !p->v2();
}
