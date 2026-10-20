#pragma force_active on
struct FnS27 {
    char pad[8];
    unsigned int flags;
};

extern "C" {
void fn_27_19CB44(FnS27 *p) {
    p->flags &= ~0x02000000u;
}
}
