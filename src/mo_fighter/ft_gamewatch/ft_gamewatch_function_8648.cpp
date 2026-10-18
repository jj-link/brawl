#pragma force_active on
extern char lbl_107_data_46A4[];

struct Fn107Obj {
    void *vtbl;
    unsigned char flag;
};

extern "C" {
void fn_107_8648(Fn107Obj *obj, unsigned char value)
{
    obj->vtbl = lbl_107_data_46A4;
    obj->flag = value;
}
}
