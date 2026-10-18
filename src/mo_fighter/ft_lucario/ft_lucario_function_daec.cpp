#pragma force_active on
extern "C" unsigned char lbl_118_data_63C8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_118_DAEC(MemberStorage* object) {
    object->vtable = (void*)lbl_118_data_63C8;
    return object;
}