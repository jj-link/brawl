#pragma force_active on
extern "C" {

struct Base5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int target();
};

struct Wrap {
    int pad[4];
    Base5 sub;
};

int fn_27_1E4DC4(Wrap* w) {
    return w->sub.target();
}

}
