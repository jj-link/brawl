#pragma force_active on
extern unsigned char lbl_80529858[0x90];
extern unsigned char* lbl_8059EDD0;
extern int fn_8022F294(int, int, int);

int fn_802324E0(int arg) {
    return fn_8022F294(lbl_80529858[0x7d], lbl_8059EDD0[2], arg);
}
