#pragma force_active on
extern "C" unsigned char lbl_113_data_AE80[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_113_25D30(MemberStorage* object) {
    object->vtable = lbl_113_data_AE80;
    return object;
}
