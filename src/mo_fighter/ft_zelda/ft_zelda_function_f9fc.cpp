#pragma force_active on
extern "C" unsigned char lbl_104_data_74A0[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_104_F9FC(MemberStorage* object) {
    object->vtable = lbl_104_data_74A0;
}
