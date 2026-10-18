#pragma force_active on
extern char lbl_104_data_2FA8[];

struct FtObj {
    void *vtbl;
    unsigned char kind;
};

extern "C" {
void fn_104_7858(struct FtObj *obj, unsigned char kind)
{
    obj->vtbl = lbl_104_data_2FA8;
    obj->kind = kind;
}
}
