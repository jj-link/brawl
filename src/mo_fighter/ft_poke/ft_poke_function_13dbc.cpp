#pragma force_active on
extern "C" unsigned char lbl_116_data_7CB0[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_116_13DBC(MemberStorage* object) {
    object->vtable = lbl_116_data_7CB0;
    return object;
}
