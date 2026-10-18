#pragma force_active on
struct Obj {
    void *vtbl;
    unsigned char flag;
};

extern "C" {
extern char lbl_115_data_32BC[];

void fn_115_6654(Obj *obj, unsigned char v)
{
    obj->vtbl = lbl_115_data_32BC;
    obj->flag = v;
}
}
