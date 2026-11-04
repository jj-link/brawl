#pragma force_active on
extern int *lbl_805A04D0;
extern int *lbl_805A04D4;
extern int *lbl_805A04D8;
extern int *lbl_805A04DC;
extern int *lbl_805A04E0;
extern int *lbl_805A04E4;
extern int *lbl_805A04E8;

extern "C" int **fn_801704DC(void *, unsigned int id) {
    switch (id) {
    case 0: return &lbl_805A04D0;
    case 1: return &lbl_805A04D4;
    case 7: return &lbl_805A04D8;
    case 8: return &lbl_805A04DC;
    case 10: return &lbl_805A04E0;
    case 5: return &lbl_805A04E4;
    case 9: return &lbl_805A04E8;
    default: return 0;
    }
}