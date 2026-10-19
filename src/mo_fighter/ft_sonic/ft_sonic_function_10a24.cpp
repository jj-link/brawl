#pragma force_active on
extern "C" unsigned char lbl_123_data_67C0[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_123_10A24(MemberStorage* object) {
    object->vtable = lbl_123_data_67C0;
    return object;
}
