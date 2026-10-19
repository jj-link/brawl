#pragma force_active on
extern "C" unsigned char lbl_95_data_8114[];

struct MemberStorage {
    void* vtable;
};

extern "C" void* fn_95_1100C(MemberStorage* object) {
    object->vtable = lbl_95_data_8114;
    return object;
}
