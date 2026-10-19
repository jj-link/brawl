#pragma force_active on
extern "C" unsigned char lbl_122_data_D8D8[];

namespace {
struct VtableStorage {
    void *vtable;
};
}

extern "C" void fn_122_14FC4(VtableStorage *object)
{
    object->vtable = lbl_122_data_D8D8;
}
