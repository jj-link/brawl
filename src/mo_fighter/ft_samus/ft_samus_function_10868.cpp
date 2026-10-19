#pragma force_active on
extern "C" unsigned char lbl_94_data_99D0[];

namespace {
struct MemberStorage {
    void *vtable;
};
}

extern "C" void fn_94_10868(MemberStorage *object) {
    object->vtable = lbl_94_data_99D0;
}
