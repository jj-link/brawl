#pragma force_active on
extern "C" unsigned char lbl_109_data_6680[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_109_E1F0(MemberStorage* object) {
    object->vtable = lbl_109_data_6680;
    return object;
}
