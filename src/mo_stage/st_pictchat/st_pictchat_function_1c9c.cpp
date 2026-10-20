#pragma force_active on
class Object {
    char padding[0x3C];

public:
#define V(N) virtual void slot##N();
#define V10(N) \
    V(N##0) V(N##1) V(N##2) V(N##3) V(N##4) \
    V(N##5) V(N##6) V(N##7) V(N##8) V(N##9)

    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6)
    V10(7) V10(8) V10(9) V10(10) V10(11) V10(12) V10(13)
    V(140) V(141) V(142)

#undef V10
#undef V

    virtual void target();
};

extern "C" void fn_73_1C9C(Object* self) {
    self->target();
}
