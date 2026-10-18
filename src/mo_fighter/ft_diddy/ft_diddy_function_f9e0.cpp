#pragma force_active on
extern "C" unsigned char lbl_115_data_77D8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_115_F9E0(MemberStorage* object) {
    object->vtable = lbl_115_data_77D8;
    return object;
}
