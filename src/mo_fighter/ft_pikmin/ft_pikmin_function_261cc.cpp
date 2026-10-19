#pragma force_active on
extern "C" unsigned char lbl_113_data_AFF8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_113_261CC(MemberStorage* object) {
    object->vtable = lbl_113_data_AFF8;
}
