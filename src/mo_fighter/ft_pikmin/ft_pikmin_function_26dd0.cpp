#pragma force_active on
extern "C" unsigned char lbl_113_data_B220[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_113_26DD0(MemberStorage* object) {
    object->vtable = lbl_113_data_B220;
    return object;
}
