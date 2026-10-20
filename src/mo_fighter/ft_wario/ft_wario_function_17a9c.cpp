#pragma force_active on
extern "C" unsigned char lbl_110_data_8320[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_110_17A9C(MemberStorage* object) {
    object->vtable = lbl_110_data_8320;
    return object;
}
