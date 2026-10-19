#pragma force_active on
extern "C" unsigned char lbl_112_data_8B78[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void fn_112_12FB4(MemberStorage* object) {
    object->vtable = lbl_112_data_8B78;
}
