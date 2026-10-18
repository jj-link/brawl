#pragma force_active on
namespace {
struct VtableStorage {
    void *vtable;
};

extern "C" unsigned char lbl_102_data_601C[];
}

extern "C" void fn_102_E104(VtableStorage *object)
{
    object->vtable = (void *)lbl_102_data_601C;
}