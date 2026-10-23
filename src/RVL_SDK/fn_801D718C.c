#pragma force_active on
extern int lbl_8059E9B8;

int fn_801D718C(int size, int alignment) {
    int mask = ~(alignment - 1);
    int result = mask & ((lbl_8059E9B8 + alignment) - 1);
    size = (int)(result + size);
    lbl_8059E9B8 = mask & ((size + alignment) - 1);
    return result;
}
