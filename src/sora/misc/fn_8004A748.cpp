#pragma force_active on
// main/fn_8004A748.c
// Provenance: reconstructs build/RSBE01_02/asm/main/fn_8004A748.s
// Simple setter storing its argument into the .sdata word lbl_805A0398.

extern int lbl_805A0398;

extern "C" void fn_8004A748(int arg0) {
    lbl_805A0398 = arg0;
}
