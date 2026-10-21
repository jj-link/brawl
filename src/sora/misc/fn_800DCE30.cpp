#pragma force_active on

struct Inner {
    int pad[9];
    int val;
};

struct Outer {
    int pad[30];
    Inner* ptr;
};

extern "C" int fn_800DCE30(Outer* o) {
    return o->ptr->val;
}
