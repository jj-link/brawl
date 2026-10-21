#pragma force_active on
extern "C" {
extern unsigned long lbl_8059E978;

unsigned int fn_801D3674(void) {
    lbl_8059E978 = lbl_8059E978 * 0x19660D + 0x3C6EF35F;
    return lbl_8059E978 >> 16;
}
}
