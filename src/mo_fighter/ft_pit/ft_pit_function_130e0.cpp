#pragma force_active on
extern "C" unsigned char lbl_112_data_8C30[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_112_130E0(MemberStorage* object) {
    object->vtable = lbl_112_data_8C30;
    return object;
}
