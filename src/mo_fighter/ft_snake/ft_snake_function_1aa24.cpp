#pragma force_active on
extern "C" unsigned char lbl_122_data_E7C8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_122_1AA24(MemberStorage* object) {
    object->vtable = lbl_122_data_E7C8;
    return object;
}
