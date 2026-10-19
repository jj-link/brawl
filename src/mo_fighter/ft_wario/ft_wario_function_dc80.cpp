#pragma force_active on
extern "C" unsigned char lbl_110_data_6630[0x40];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_110_DC80(MemberStorage* object) {
    object->vtable = lbl_110_data_6630;
    return object;
}
