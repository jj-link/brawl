#pragma force_active on
extern "C" unsigned char lbl_113_data_701C[];

struct Obj {
    void* vtable;
    void* member;
};

extern "C" void fn_113_6420(Obj* object, void* value) {
    object->member = value;
    object->vtable = lbl_113_data_701C;
}
