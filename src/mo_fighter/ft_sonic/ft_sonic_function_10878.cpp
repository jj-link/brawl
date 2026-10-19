#pragma force_active on
extern "C" unsigned char lbl_123_data_6748[];

namespace {
struct VtableStorage {
    void* vtable;
};
}

extern "C" void* fn_123_10878(VtableStorage* object) {
    object->vtable = lbl_123_data_6748;
    return object;
}
