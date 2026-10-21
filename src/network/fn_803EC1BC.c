#pragma force_active on
struct Lbl80598080 {
    void (*fp)(signed char);
    char pad[0x14];
};
extern struct Lbl80598080 lbl_80598080;

void fn_803EC1BC(signed char arg) {
    if (lbl_80598080.fp) {
        lbl_80598080.fp(arg);
    }
}
