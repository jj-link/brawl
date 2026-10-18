#pragma force_active on
extern "C" unsigned char lbl_92_data_6AF0[];

struct VtableHolder {
    void* vtable;
};

extern "C" void* fn_92_10314(VtableHolder* object) {
    object->vtable = lbl_92_data_6AF0;
    return object;
}
