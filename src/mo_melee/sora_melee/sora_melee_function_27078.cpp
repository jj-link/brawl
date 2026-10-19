#pragma force_active on
struct Source;

struct Inner {
    virtual void f0();
    virtual Source* f1(int arg);
};

struct Outer {
    char pad[0x28];
    Inner* inner;
};

extern "C" void fn_27_2EF54(Source* self, unsigned short val);

extern "C" void fn_27_27078(Outer* self, unsigned short val, int arg) {
    fn_27_2EF54(self->inner->f1(arg), val);
}
