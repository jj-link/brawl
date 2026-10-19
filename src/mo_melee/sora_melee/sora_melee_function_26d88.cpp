#pragma force_active on
struct SubObj {
    virtual void f0();
    virtual int f1(int value);
};

struct Holder {
    char pad[0x28];
    SubObj* sub;
};

extern "C" int fn_27_2EE9C(int value, int a, int b);

extern "C" int fn_27_26D88(Holder* self, int a, int b) {
    return fn_27_2EE9C(self->sub->f1(b), a, 1);
}
