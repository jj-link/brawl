#pragma force_active on
extern "C" {

extern unsigned char lbl_115_data_75C8[];

typedef struct Object
{
    void *vtable;
} Object;

void fn_115_DE14(Object *object)
{
    object->vtable = lbl_115_data_75C8;
}

}
