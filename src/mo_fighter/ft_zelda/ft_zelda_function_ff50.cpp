#pragma force_active on
extern "C" unsigned char lbl_104_data_7518[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_104_FF50(MemberStorage* object) {
    object->vtable = lbl_104_data_7518;
}
