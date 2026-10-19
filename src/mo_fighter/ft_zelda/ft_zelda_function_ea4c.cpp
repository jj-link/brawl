#pragma force_active on
extern "C" unsigned char lbl_104_data_7338[];

struct MemberStorage {
    void* vtable;
};

extern "C" void* fn_104_EA4C(MemberStorage* object) {
    object->vtable = lbl_104_data_7338;
    return object;
}
