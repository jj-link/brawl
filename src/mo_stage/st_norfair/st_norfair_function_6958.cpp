#pragma force_active on
struct S {
    char pad[8];
    int val : 4;
};

extern "C" int fn_54_6958(S* s) {
    return s->val;
}
