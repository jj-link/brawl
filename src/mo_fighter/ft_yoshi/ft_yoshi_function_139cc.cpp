#pragma force_active on
extern "C" unsigned char lbl_95_data_8450[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_95_139CC(MemberStorage* object) {
    object->vtable = lbl_95_data_8450;
    return object;
}
