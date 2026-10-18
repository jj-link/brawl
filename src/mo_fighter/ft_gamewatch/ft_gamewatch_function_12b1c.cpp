#pragma force_active on
extern "C" unsigned char lbl_107_data_9188[0x40];

struct SomeStruct {
    void **ptr;
};

extern "C" void fn_107_12B1C(SomeStruct *obj)
{
    obj->ptr = (void **)&lbl_107_data_9188[0];
}
