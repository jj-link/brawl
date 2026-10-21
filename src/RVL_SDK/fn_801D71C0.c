#pragma force_active on
extern int lbl_8059E9BC;

void *fn_801D71C0(int size, int alignment) {
    char *result;
    int mask;

    mask = ~(alignment - 1);
    result = (char *)(mask & ((lbl_8059E9BC + alignment) - 1));
    size = (int)(result + size);
    lbl_8059E9BC = mask & ((size + alignment) - 1);
    return result;
}
