#pragma force_active on
class soSub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

class soOuter {
public:
    char pad[0x10];
    soSub sub;
};

extern "C" {
void fn_27_F44D4(soOuter* p) {
    p->sub.v1();
}
}
