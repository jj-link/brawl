#pragma force_active on
extern "C" unsigned char lbl_122_data_D7E0[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_122_14640(MemberStorage* object) {
    object->vtable = lbl_122_data_D7E0;
    return object;
}
