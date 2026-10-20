#pragma force_active on
extern "C" unsigned char lbl_104_data_C448[];

struct MemberStorage {
    void* vtable;
};

extern "C" void* fn_104_1F9B4(MemberStorage* object) {
    object->vtable = lbl_104_data_C448;
    return object;
}
