#pragma force_active on
extern "C" unsigned char lbl_94_data_C5D8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_94_1A074(MemberStorage* object) {
    object->vtable = lbl_94_data_C5D8;
    return object;
}
