#pragma force_active on
extern "C" {
extern unsigned char lbl_107_data_9650[];
}

namespace {
struct VTableHolder {
    void* vtable;
};
}

extern "C" void fn_107_145DC(VTableHolder* object) {
    object->vtable = (void*)lbl_107_data_9650;
}
