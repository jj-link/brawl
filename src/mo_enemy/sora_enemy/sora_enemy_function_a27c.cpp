#pragma force_active on
struct Inner {
    int pad;
    int val;
};

struct Outer {
    Inner* inner;
    unsigned char flag;
};

extern "C" int fn_41_A27C(Outer* o) {
    if (o->flag == 1) {
        return 0;
    }
    return o->inner->val != 0;
}
