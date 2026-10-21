#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void v3(int a, int b, int c, void* d);
};

class Outer {
public:
    virtual void v0();
    Inner* inner;
};

extern "C" {
void fn_801C6AF4(Outer* self, int a, int b) {
    self->inner->v3(a, b, 0, (char*)self + 8);
}
}
