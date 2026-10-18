#pragma force_active on
extern "C" unsigned char lbl_115_data_7A40[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_115_111C4(MemberStorage* object) {
    object->vtable = lbl_115_data_7A40;
    return object;
}
