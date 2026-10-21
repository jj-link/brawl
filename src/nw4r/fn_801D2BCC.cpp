#pragma force_active on
extern "C" int fn_802025CC(void);

extern "C" int fn_801D2BCC(void) {
    return fn_802025CC() * 0x12C;
}
