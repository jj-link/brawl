#pragma force_active on
extern "C" {
extern const float lbl_10_rodata_6B8;
extern const float lbl_10_rodata_6A8;
extern char lbl_10_data_BA8[];

void setFrameVisible__8MuObjectFf(void*, float);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);

void fn_10_19298(char* self, int arg) {
    setFrameVisible__8MuObjectFf(
        *(void**)(self + 0x144),
        arg ? lbl_10_rodata_6B8 : lbl_10_rodata_6A8);

    if (!arg) {
        printf__5MuMsgFUlPCce(
            *(void**)(self + 0x40c), 0x1d, lbl_10_data_BA8);
        printf__5MuMsgFUlPCce(
            *(void**)(self + 0x40c), 0x1e, lbl_10_data_BA8);
    }
}
}
