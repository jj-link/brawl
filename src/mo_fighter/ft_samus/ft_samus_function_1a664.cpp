#pragma force_active on
namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" unsigned char lbl_94_data_C6D8[];

extern "C" void fn_94_1A664(MemberStorage* object) {
    object->vtable = lbl_94_data_C6D8;
}
