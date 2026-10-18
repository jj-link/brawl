#pragma force_active on
extern char lbl_116_data_2DBC[];

struct FtPokeObj {
    void *vtbl;
    unsigned char kind;
};

extern "C" {
void fn_116_72AC(struct FtPokeObj *obj, int kind)
{
    obj->vtbl = lbl_116_data_2DBC;
    obj->kind = kind;
}
}
