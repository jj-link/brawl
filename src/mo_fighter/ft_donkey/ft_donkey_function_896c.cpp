#pragma force_active on
extern "C" {
extern char lbl_92_data_1D04[];

typedef struct FtObj {
    void *vtbl;
    int pad04;
    int pad08;
    int pad0C;
    int f10;
    int f14;
    int f18;
} FtObj;

void fn_92_896C(FtObj *obj, int a, int b, int c)
{
    obj->vtbl = lbl_92_data_1D04;
    obj->f10 = a;
    obj->f14 = b;
    obj->f18 = c;
}
}
