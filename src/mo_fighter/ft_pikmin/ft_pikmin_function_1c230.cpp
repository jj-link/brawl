#pragma force_active on
struct FnObj {
    void *vtbl;
    unsigned char flag;
    unsigned char enabled : 1;
    unsigned char padding : 7;
    unsigned char state;
};

extern "C" {
void fn_113_7F94(FnObj*, int);
extern char lbl_113_data_80A4[];
}

extern "C" FnObj* fn_113_1C230(FnObj* obj, int value) {
    fn_113_7F94(obj, value);
    obj->enabled = value == 0;
    obj->state = 0;
    obj->vtbl = lbl_113_data_80A4;
    return obj;
}
