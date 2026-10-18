#pragma force_active on
struct ClassWithVtable {
    void* vtable;
};

extern "C" extern char lbl_107_data_9548[64];

extern "C" void fn_107_13C8C(ClassWithVtable* object) {
    object->vtable = (void*)lbl_107_data_9548;
}
