#pragma force_active on
extern "C" unsigned char lbl_115_data_752C[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_115_DD6C(MemberStorage* object) {
    object->vtable = lbl_115_data_752C;
    return object;
}
