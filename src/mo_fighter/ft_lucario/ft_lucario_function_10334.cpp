#pragma force_active on
extern "C" unsigned char lbl_118_data_6558[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_118_10334(MemberStorage* object) {
    object->vtable = lbl_118_data_6558;
    return object;
}
