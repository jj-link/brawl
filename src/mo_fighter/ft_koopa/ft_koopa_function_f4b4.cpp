#pragma force_active on
extern "C" {
extern unsigned char lbl_102_data_6110[];

typedef struct {
    void *vptr;
} SomeStruct;

void fn_102_F4B4(SomeStruct *object)
{
    object->vptr = lbl_102_data_6110;
}
}
