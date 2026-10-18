#pragma force_active on
struct IceClimberVftable
{
    void *vtable[0x10];
};

extern "C" unsigned char lbl_105_data_7FE0[];

extern "C" void fn_105_13720(IceClimberVftable *object)
{
    object->vtable[0] = (void *)lbl_105_data_7FE0;
}
