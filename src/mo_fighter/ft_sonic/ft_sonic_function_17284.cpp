#pragma force_active on
extern "C" {
void fn_123_6D30(void*, unsigned int);
extern unsigned char lbl_123_data_719C[];
}

struct SonicObject {
    void* vtable;
    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    unsigned char state;
};

extern "C" SonicObject* fn_123_17284(SonicObject* object, unsigned int value) {
    fn_123_6D30(object, value);
    object->enabled = value == 0;
    object->state = 0;
    object->vtable = lbl_123_data_719C;
    return object;
}
