#pragma force_active on
extern "C" unsigned char lbl_122_data_10758[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_122_27B14(MemberStorage* object) {
    object->vtable = lbl_122_data_10758;
    return object;
}
