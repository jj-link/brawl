#pragma force_active on
extern int lbl_80474E98[];
extern int lbl_804DE330[];

int fn_801E5F64(int arg0) {
    int result = 0;

    if (lbl_804DE330[arg0 * 8] != -1 || lbl_80474E98[0] == arg0) {
        result = 1;
    }

    return result;
}
