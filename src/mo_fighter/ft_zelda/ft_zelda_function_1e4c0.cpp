#pragma force_active on
extern "C" unsigned char lbl_104_data_C2C8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_104_1E4C0(MemberStorage* object) {
    object->vtable = lbl_104_data_C2C8;
    return object;
}
