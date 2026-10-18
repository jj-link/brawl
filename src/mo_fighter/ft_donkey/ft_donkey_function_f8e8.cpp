#pragma force_active on
extern "C" unsigned char lbl_92_data_6858[];

struct MemberStorage {
    void* vtable;
};

extern "C" void fn_92_F8E8(MemberStorage* object) {
    object->vtable = lbl_92_data_6858;
}
