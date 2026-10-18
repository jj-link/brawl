#pragma force_active on
struct fn27_obj {
    char pad[0x38];
    int val;
};

extern "C" {
int fn_27_6AA2C(fn27_obj* p) {
    return p->val != -1;
}
}
