#pragma force_active on
extern "C" unsigned char lbl_95_data_83D8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_95_138AC(MemberStorage* object) {
    object->vtable = lbl_95_data_83D8;
}
