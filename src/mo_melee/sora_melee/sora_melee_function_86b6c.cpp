#pragma force_active on
typedef unsigned int u32;

class fn27Class {
public:
    virtual ~fn27Class();
    virtual void v2();
    virtual void v3();
    virtual bool v5();
};

extern "C" bool fn_27_86B6C(fn27Class* self) {
    return !self->v5();
}
