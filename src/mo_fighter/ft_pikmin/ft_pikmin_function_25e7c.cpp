#pragma force_active on
extern "C" unsigned char lbl_113_data_AF08[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_113_25E7C(MemberStorage* object) {
    object->vtable = lbl_113_data_AF08;
}
