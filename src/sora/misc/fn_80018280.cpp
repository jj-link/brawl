#pragma force_active on
struct Pair { int a; int b; };
extern "C" Pair lbl_804948C0[];

extern "C" void fn_80018280(Pair *dst, int idx) {
    *dst = lbl_804948C0[idx];
}
