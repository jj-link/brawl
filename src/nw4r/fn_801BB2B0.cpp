#pragma force_active on
extern "C" int fn_802025CC(void);

extern "C" int fn_801BB2B0(void) {
    return (fn_802025CC() + 0x10) * 0x48;
}
