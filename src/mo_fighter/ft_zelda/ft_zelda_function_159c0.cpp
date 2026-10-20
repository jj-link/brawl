#pragma force_active on
extern "C" unsigned char lbl_104_data_8908[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_104_159C0(MemberStorage* object) {
    object->vtable = lbl_104_data_8908;
}
