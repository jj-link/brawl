#pragma force_active on
struct Inner {
    int pad[8];
    int val;
};
struct Outer {
    int pad[10];
    Inner* ptr;
};
extern "C" int fn_802DAE54(Outer* arg0) {
    return arg0->ptr->val;
}
