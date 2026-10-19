#pragma force_active on
extern "C" unsigned char lbl_113_data_AF80[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_113_25FA8(MemberStorage* object) {
    object->vtable = lbl_113_data_AF80;
}
