#pragma force_active on
extern "C" unsigned char lbl_120_data_7030[];

struct MemberStorage {
    void* vtable;
};

extern "C" void fn_120_E0D8(MemberStorage* object) {
    object->vtable = lbl_120_data_7030;
}
