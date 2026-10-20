#pragma force_active on
extern "C" unsigned char lbl_104_data_8328[];

struct MemberStorage {
    void* vtable;
};

extern "C" void* fn_104_1390C(MemberStorage* object) {
    object->vtable = lbl_104_data_8328;
    return object;
}
