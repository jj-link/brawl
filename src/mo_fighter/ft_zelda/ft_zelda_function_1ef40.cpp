#pragma force_active on
extern "C" unsigned char lbl_104_data_C348[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_104_1EF40(MemberStorage* object) {
    object->vtable = lbl_104_data_C348;
    return object;
}
