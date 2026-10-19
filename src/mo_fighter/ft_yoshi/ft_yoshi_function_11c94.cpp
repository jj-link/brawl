#pragma force_active on
extern "C" unsigned char lbl_95_data_81E0[];

struct MemberStorage {
    void* vtable;
};

extern "C" void* fn_95_11C94(MemberStorage* object) {
    object->vtable = lbl_95_data_81E0;
    return object;
}
