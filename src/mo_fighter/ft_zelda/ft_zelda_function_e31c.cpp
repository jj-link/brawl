#pragma force_active on
extern "C" unsigned char lbl_104_data_72BC[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_104_E31C(MemberStorage* object) {
    object->vtable = lbl_104_data_72BC;
}
