#pragma force_active on
extern "C" unsigned char lbl_110_data_8230[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_110_16980(MemberStorage* object) {
    object->vtable = lbl_110_data_8230;
    return object;
}
