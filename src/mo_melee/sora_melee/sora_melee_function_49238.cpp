#pragma force_active on
extern "C" int fn_27_46F94(int a, int b, int c);

class Inner {
public:
    virtual void v0();
    virtual int v3(int x);
};

class Outer {
public:
    int pad0[8];
    int m20;
    int pad1[9];
    Inner* m48;
};

extern "C" int fn_27_49238(Outer* self, int a, int b) {
    int r = self->m48->v3(b);
    return fn_27_46F94(r, self->m20, a);
}
