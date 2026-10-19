#pragma force_active on
extern "C" unsigned char lbl_122_data_D860[];

struct MemberStorage {
    void* vtable;
};

extern "C" void* fn_122_14B78(MemberStorage* object) {
    object->vtable = lbl_122_data_D860;
    return object;
}
