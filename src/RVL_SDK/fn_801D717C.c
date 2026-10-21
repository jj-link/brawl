#pragma force_active on
// main/fn_801D717C.c
// Provenance: reconstructs build/RSBE01_02/asm/main/fn_801D717C.s
// Single stores the argument into the .sdata word lbl_8059E9BC
// (sda21-relative store of r3, no TOC/reference-parameter access).

extern int lbl_8059E9BC;

void fn_801D717C(int value) {
    lbl_8059E9BC = value;
}
