#pragma force_active on
typedef struct DBCommTable {
    unsigned char pad[0x10];
    int (*unk10)(void *, void *);
} DBCommTable;

extern DBCommTable gDBCommTable;

int fn_80405BA8(void *arg, void *arg2) {
    int temp_r3;

    temp_r3 = gDBCommTable.unk10(arg, arg2);
    return (-temp_r3 | temp_r3) >> 0x1F;
}
