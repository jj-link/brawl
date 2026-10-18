#pragma force_active on
extern "C" unsigned char lbl_92_data_69E0[];

struct MemberStorage {
    void* vtable;
};

extern "C" void fn_92_FF0C(MemberStorage* object) {
    object->vtable = lbl_92_data_69E0;
}
