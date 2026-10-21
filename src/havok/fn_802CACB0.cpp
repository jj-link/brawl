#pragma force_active on
class Inner {
public:
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual int v12(int b) = 0;
};

struct Outer {
    int pad;
    Inner* inner;
};

extern "C" int fn_802CACB0(Outer* o, int a, int b) {
    return o->inner->v12(b);
}
