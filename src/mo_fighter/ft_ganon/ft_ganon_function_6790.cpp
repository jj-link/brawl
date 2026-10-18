#pragma force_active on
extern "C" {
extern char lbl_109_data_2204[];

typedef struct {
    void *vtbl;
    unsigned char flag;
} FtObj;

void fn_109_6790(FtObj *obj, unsigned char val)
{
    obj->vtbl = lbl_109_data_2204;
    obj->flag = val;
}
}
