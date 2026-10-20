#pragma force_active on
extern "C" unsigned char lbl_104_data_C3C8[];

struct MemberStorage {
    void* vtable;
};

extern "C" void* fn_104_1F12C(MemberStorage* object) {
    object->vtable = lbl_104_data_C3C8;
    return object;
}
