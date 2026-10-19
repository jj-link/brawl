#pragma force_active on
extern "C" unsigned char lbl_95_data_7B28[];

namespace {
struct ObjectHeader {
    void* vtable;
};
}

extern "C" void fn_95_F204(ObjectHeader* object) {
    object->vtable = lbl_95_data_7B28;
}
