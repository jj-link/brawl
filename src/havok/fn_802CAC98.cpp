#pragma force_active on
class Inner {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int v11(int a);
};

struct Outer {
    int pad;
    Inner* inner;
};

extern "C" int fn_802CAC98(Outer* o, int a, int b) {
    return o->inner->v11(b);
}
