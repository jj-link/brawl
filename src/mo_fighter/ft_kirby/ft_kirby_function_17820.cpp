#pragma force_active on
extern "C" unsigned char lbl_96_data_B7BC[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_96_17820(MemberStorage* object) {
    object->vtable = lbl_96_data_B7BC;
    return object;
}
