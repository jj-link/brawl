#pragma force_active on
struct FnState {
    char pad[0x968];
    int a;
    int b;
};

extern "C" {
int fn_40_42DD0(FnState* p) {
    if (p->a >= 3 && p->b >= 3) {
        return 1;
    }
    return 0;
}
}
