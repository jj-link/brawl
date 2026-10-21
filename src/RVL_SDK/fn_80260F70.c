#pragma force_active on
typedef struct {
    int pad[2];
    int x8;
    int xC;
    int x10;
    int x14;
} StructName;

int fn_80260F70(StructName *arg0, int arg1, int arg2) {
    int sum;
    if (arg1 == 0) {
        return -1;
    }
    if (arg2 == 0) {
        return -1;
    }
    if (arg1 & 0x1F) {
        return -1;
    }
    sum = arg1 + arg2;
    arg0->x8 = arg1;
    arg0->xC = arg1;
    arg0->x10 = sum;
    arg0->x14 = sum - 0xA;
    return 0;
}
