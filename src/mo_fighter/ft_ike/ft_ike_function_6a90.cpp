#pragma force_active on
extern "C" void fn_119_580C(void* object, int value);
extern "C" unsigned char lbl_119_data_13B0[];

struct Fn119Object {
    unsigned int* secondaryTable;  // +0x00
    unsigned int reserved;         // +0x04
    unsigned int* table;           // +0x08
    unsigned int arg0;              // +0x0C
    unsigned int arg1;              // +0x10
    unsigned int arg2;              // +0x14
    unsigned int arg3;              // +0x18
    unsigned int arg4;              // +0x1C
    unsigned int arg5;              // +0x20
};

extern "C" Fn119Object* fn_119_6A90(
    Fn119Object* object,
    unsigned int arg0,
    unsigned int arg1,
    unsigned int arg2,
    unsigned int arg3,
    unsigned int arg4,
    unsigned int arg5
) {
    fn_119_580C(object, 0);
    object->table = (unsigned int*)lbl_119_data_13B0;
    object->secondaryTable = (unsigned int*)(lbl_119_data_13B0 + 8);
    object->arg0 = arg0;
    object->arg1 = arg1;
    object->arg2 = arg2;
    object->arg3 = arg3;
    object->arg4 = arg4;
    object->arg5 = arg5;
    return object;
}
