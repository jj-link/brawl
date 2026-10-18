#pragma force_active on
extern "C" unsigned char lbl_115_data_7C20[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_115_130F0(MemberStorage* object) {
    object->vtable = lbl_115_data_7C20;
    return object;
}
