#pragma force_active on
extern "C" unsigned char lbl_96_data_D9AC[0x40];

struct S { void *vtable; };

extern "C" void fn_96_28FB8(S *object)
{
    object->vtable = lbl_96_data_D9AC;
}
