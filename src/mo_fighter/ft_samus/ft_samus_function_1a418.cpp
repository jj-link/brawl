#pragma force_active on
extern "C" unsigned char lbl_94_data_C658[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_94_1A418(MemberStorage* object) {
    object->vtable = lbl_94_data_C658;
    return object;
}
