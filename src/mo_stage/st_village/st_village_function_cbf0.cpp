#pragma force_active on
class StBase {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool v5();
};

extern "C" bool fn_70_CBF0(StBase* self) {
    return !self->v5();
}
