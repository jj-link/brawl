#pragma force_active on
extern "C" unsigned char lbl_104_data_82B0[];

struct MemberStorage {
    void* vtable;
};

extern "C" void* fn_104_1376C(MemberStorage* object) {
    object->vtable = lbl_104_data_82B0;
    return object;
}
