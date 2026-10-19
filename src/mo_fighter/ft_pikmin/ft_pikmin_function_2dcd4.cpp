#pragma force_active on
extern "C" unsigned char lbl_113_data_C118[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_113_2DCD4(MemberStorage* object) {
    object->vtable = lbl_113_data_C118;
    return object;
}
