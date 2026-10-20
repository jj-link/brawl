#pragma force_active on
extern "C" unsigned char lbl_10_data_140[0x20];

struct Object {
    void* vtable;
    unsigned char flag : 1;
    unsigned char flags : 7;
    unsigned char padding[3];
    unsigned int value;
};

extern "C" void fn_10_3D0(Object* obj) {
    obj->vtable = lbl_10_data_140;
    obj->flag = 0;
    obj->value = 0;
}
