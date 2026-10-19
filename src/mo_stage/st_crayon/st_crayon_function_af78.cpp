#pragma force_active on
class grCrayonBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" {
bool fn_56_AF78(grCrayonBase* p) {
    return !p->v3();
}
}
