#pragma force_active on
extern "C" unsigned char lbl_116_data_C000[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_116_23F3C(MemberStorage* object) {
    object->vtable = lbl_116_data_C000;
}
