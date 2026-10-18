#pragma force_active on
typedef struct {
    void *ptr;
    unsigned char b;
} FtPitObj;

extern char lbl_112_data_2880[];

extern "C" {
void fn_112_7674(FtPitObj *obj, unsigned char b);
}

void fn_112_7674(FtPitObj *obj, unsigned char b)
{
    obj->ptr = lbl_112_data_2880;
    obj->b = b;
}
