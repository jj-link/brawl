#pragma force_active on

class Class_17F48 {
public:
    virtual void fn_27_C51D4(int, int);
};

struct Holder {
    int padding[2];
    int flag;
    int padding2[2];
    Class_17F48* target;
};

extern "C" int fn_27_C3AF8(Holder* holder, int a, int b) {
    if (!holder->flag || !holder->target) {
        return 0;
    }
    holder->target->fn_27_C51D4(b, a);
}
