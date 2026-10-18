#pragma force_active on
extern "C" unsigned char lbl_118_data_6444[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_118_DADC(MemberStorage* object) {
    object->vtable = lbl_118_data_6444;
    return object;
}
