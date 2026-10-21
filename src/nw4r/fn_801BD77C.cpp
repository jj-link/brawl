#pragma force_active on
extern "C" int fn_802025CC(void);

extern "C" int fn_801BD77C(void) {
    return (fn_802025CC() + 1) * 0xEC;
}
