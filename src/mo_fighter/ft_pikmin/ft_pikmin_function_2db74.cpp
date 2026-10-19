#pragma force_active on
extern "C" unsigned char lbl_113_data_C0A0[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_113_2DB74(MemberStorage* object) {
    object->vtable = lbl_113_data_C0A0;
}
