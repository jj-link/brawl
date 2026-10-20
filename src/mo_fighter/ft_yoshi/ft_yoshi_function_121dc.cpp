#pragma force_active on
extern "C" void* lbl_95_data_8260[];

struct MemberStorage {
    void* vtable;
};

extern "C" void fn_95_121DC(MemberStorage* object) {
    object->vtable = lbl_95_data_8260;
}
