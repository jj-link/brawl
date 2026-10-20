#pragma force_active on
extern "C" unsigned char lbl_95_data_82D8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_95_12D70(MemberStorage* object) {
    object->vtable = lbl_95_data_82D8;
    return object;
}
