#pragma force_active on
extern "C" int fn_80204A70(int, int, int);
extern int* lbl_805A0570;
extern int lbl_805A0574;

extern "C" int fn_801BBC98(int size) {
    int result = fn_80204A70(lbl_805A0570[1], size, 4);
    lbl_805A0570[2]++;
    lbl_805A0574 += (size + 3) & ~3;
    return result;
}
