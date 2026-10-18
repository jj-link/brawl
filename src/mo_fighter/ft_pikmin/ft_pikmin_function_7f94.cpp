#pragma force_active on
struct FnObj {
    void *vtbl;
    unsigned char flag;
};

extern "C" char lbl_113_data_2A0C[];

extern "C" void fn_113_7F94(FnObj *obj, unsigned char value)
{
    obj->vtbl = lbl_113_data_2A0C;
    obj->flag = value;
}
