#pragma force_active on
struct Fn113Obj {
    void* vtable;
    int pad;
    void* arg;
    int index;
};

extern "C" void fn_113_7F94(Fn113Obj* obj, int value);
extern "C" unsigned char lbl_113_data_7F7C[];

extern "C" Fn113Obj* fn_113_16DF4(Fn113Obj* obj, void* arg) {
    fn_113_7F94(obj, 0);
    obj->vtable = lbl_113_data_7F7C;
    obj->arg = arg;
    obj->index = -1;
    return obj;
}
