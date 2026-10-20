#pragma force_active on
extern "C" unsigned char lbl_95_data_84C8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_95_13B68(MemberStorage* object) {
    object->vtable = lbl_95_data_84C8;
}
