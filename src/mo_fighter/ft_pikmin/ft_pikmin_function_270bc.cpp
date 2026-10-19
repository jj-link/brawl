#pragma force_active on
extern "C" unsigned char lbl_113_data_B2A8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_113_270BC(MemberStorage* object) {
    object->vtable = lbl_113_data_B2A8;
    return object;
}
