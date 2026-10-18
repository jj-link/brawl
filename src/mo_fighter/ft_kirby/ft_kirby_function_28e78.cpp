#pragma force_active on
extern "C" const float lbl_96_rodata_570;

struct KirbyObject {
    int value;
    unsigned char flag;
    unsigned char padding[3];
    float scalar;
    unsigned char padding2[4];
    unsigned char state;
};

extern "C" void fn_96_28E78(KirbyObject* object, int value) {
    object->value = value;
    object->flag = 0;
    object->scalar = lbl_96_rodata_570;
    object->state = 0;
}
