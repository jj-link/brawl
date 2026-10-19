#pragma force_active on
extern "C" unsigned char lbl_110_data_65A8[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_110_DB18(MemberStorage* object) {
    object->vtable = lbl_110_data_65A8;
    return object;
}
