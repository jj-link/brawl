#pragma force_active on
struct KirbyObject {
    void* vtable;
    unsigned char padding[1];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    unsigned char state;
};

extern "C" void fn_96_1FD0(void*, int);
extern unsigned char lbl_96_data_CDD0[];

extern "C" KirbyObject* fn_96_2775C(KirbyObject* object, unsigned int value) {
    fn_96_1FD0(object, value);
    object->enabled = value == 0;
    object->state = 0;
    object->vtable = lbl_96_data_CDD0;
    return object;
}
