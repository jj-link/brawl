#pragma force_active on
extern "C" unsigned char lbl_112_data_8CA8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_112_133A0(MemberStorage* object) {
    object->vtable = lbl_112_data_8CA8;
    return object;
}
