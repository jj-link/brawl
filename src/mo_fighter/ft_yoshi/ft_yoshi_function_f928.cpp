#pragma force_active on
extern "C" unsigned char lbl_95_data_7DF8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_95_F928(MemberStorage* object) {
    object->vtable = lbl_95_data_7DF8;
    return object;
}
