#pragma force_active on
extern char lbl_80487E98[];

struct Local {
    void* p;
    short a;
    short s;
} __attribute__((aligned(16)));

extern "C" void* fn_802E21DC() {
    Local local;
    if (&local != 0) {
        local.s = 1;
        local.p = lbl_80487E98;
    }
    return local.p;
}
