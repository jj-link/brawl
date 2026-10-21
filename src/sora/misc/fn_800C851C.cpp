#pragma force_active on
// main/fn_800C851C
// Reads the one-byte flag at 0x8059E742 (sdata) and returns it.
typedef unsigned char u8;

extern "C" extern u8 lbl_8059E742;

extern "C" u8 fn_800C851C(void) {
    return lbl_8059E742;
}
