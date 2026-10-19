#pragma force_active on
extern "C" unsigned char lbl_94_data_C7D8[];

struct MemberStorage {
    void* vtable;
};

extern "C" void* fn_94_1AB3C(MemberStorage* object) {
    object->vtable = lbl_94_data_C7D8;
    return object;
}
