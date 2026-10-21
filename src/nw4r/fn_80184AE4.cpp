#pragma force_active on
// main/... (decompilation of fn_80184AE4)
// Sets the small-data-area pointer lbl_805A0510 to the address of lbl_805A0500.
// The target code uses "li r0, lbl_805A0500@sda21 / stw r0, lbl_805A0510@sda21(r0)",
// i.e. the pointer is kept as a 32-bit pointer to a double-sized object so that the
// whole store collapses into a single small-data-area pair of instructions.

typedef double f64;
typedef f64* f64p;

extern "C" extern f64 lbl_805A0500;
extern "C" extern f64p lbl_805A0510;

extern "C" void fn_80184AE4(void) {
    lbl_805A0510 = &lbl_805A0500;
}

__declspec(section ".ctors") extern void* const fn_80184AE4_ctor = (void*)fn_80184AE4;
