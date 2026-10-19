#pragma force_active on
class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual Inner* v2();
};

struct Mid {
    char pad[0x18];
    Inner* p18;
};

struct Outer {
    char pad[0xd8];
    Mid* pd8;
};

struct Top {
    char pad[0x1c];
    Outer* p1c;
};

extern "C" void fn_27_496A4(const Top* self) {
    Inner* p = self->p1c->pd8->p18;
    p->v2()->v2();
}
