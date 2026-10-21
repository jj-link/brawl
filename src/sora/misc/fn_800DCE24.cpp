#pragma force_active on

struct Inner {
    int data[8];
    int val;
};

struct Outer {
    int data[30];
    Inner* ptr;
};

extern "C" int fn_800DCE24(Outer* arg) {
    return arg->ptr->val;
}
