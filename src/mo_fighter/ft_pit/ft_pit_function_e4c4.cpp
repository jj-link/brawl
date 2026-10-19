#pragma force_active on
extern "C" unsigned char lbl_112_data_6A4C[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_112_E4C4(MemberStorage* object) {
    object->vtable = lbl_112_data_6A4C;
    return object;
}
