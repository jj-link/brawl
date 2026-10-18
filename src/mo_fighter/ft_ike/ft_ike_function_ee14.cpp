#pragma force_active on
extern "C" unsigned char lbl_119_data_5EA0[];

struct SomeStruct {
    const unsigned char *vptr;
};

extern "C" void fn_119_EE14(SomeStruct *object)
{
    object->vptr = lbl_119_data_5EA0;
}