#pragma force_active on
extern "C" {

class Small {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

class Big {
public:
    char buf[0x7b90];
};

class Obj : public Big, public Small {
};

void fn_126_7A44(Obj* self) {
    self->f2();
}

}
