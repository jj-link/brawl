#pragma force_active on
extern "C" unsigned char lbl_109_data_647C[];

namespace {
struct MemberStorage {
    void *vtable;
};
}

extern "C" void *fn_109_D334(MemberStorage *object) {
    object->vtable = (void *)lbl_109_data_647C;
    return object;
}