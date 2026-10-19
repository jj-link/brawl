#pragma force_active on
extern "C" unsigned char lbl_120_data_70C8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_120_EEA4(MemberStorage* object) {
    object->vtable = lbl_120_data_70C8;
    return object;
}
