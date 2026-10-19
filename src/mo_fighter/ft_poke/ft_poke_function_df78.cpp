#pragma force_active on
extern "C" unsigned char lbl_116_data_6EB0[];

struct MemberStorage {
    void* vtable;
};

extern "C" MemberStorage* fn_116_DF78(MemberStorage* object) {
    object->vtable = lbl_116_data_6EB0;
    return object;
}
