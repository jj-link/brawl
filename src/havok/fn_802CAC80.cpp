#pragma force_active on
class Inner {
public:
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08(int x) = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
};

struct Outer {
    int pad;
    Inner* inner;
};

extern "C" void fn_802CAC80(Outer* o, int a, int b) {
    o->inner->v08(b);
}
