#pragma force_active on
extern "C" unsigned char lbl_102_data_6094[];

namespace {
struct Unknown {
    void *vtable;
};
}

extern "C" void fn_102_E114(Unknown *obj)
{
    obj->vtable = (void *)&lbl_102_data_6094;
}
