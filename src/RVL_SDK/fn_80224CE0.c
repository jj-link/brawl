#pragma force_active on
struct S {
    char pad[0x3C];
    int field;
};

extern struct S* lbl_804F6810[];

void fn_80224CE0(int arg0, int arg1) {
    struct S *p = lbl_804F6810[arg0];
    if (p->field == 0) {
        p->field = (arg1 == 0) ? 0 : -3;
    }
}
