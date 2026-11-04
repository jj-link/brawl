#pragma force_active on
typedef struct {
    int x0;
    void *x4;
    int x8;
    int xC;
    int x10;
    int x14;
    int x18;
    int x1C;
    int x20;
} StructName;

int fn_8037B4F8(int arg0, StructName *arg1, char *arg2, int arg3) {
    if (arg0 == 0) {
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    if (arg3 <= 0) {
        return 0;
    }
    arg1->x0 = arg0;
    arg1->x4 = arg2;
    arg1->x8 = arg3;
    arg1->xC = 0;
    arg1->x10 = 0;
    arg1->x14 = 0;
    arg1->x18 = 1;
    arg1->x1C = 1;
    arg1->x20 = 0;
    *arg2 = 0;
    return 1;
}