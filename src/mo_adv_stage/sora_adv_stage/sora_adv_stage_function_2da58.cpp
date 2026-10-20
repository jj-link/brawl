#pragma force_active on
extern "C" void fn_27_260604(void*, unsigned int, int);

struct Object {
    unsigned char pad0[0x40];
    int state;
    unsigned char pad44[0x28];
    unsigned char : 1;
    unsigned char flag : 1;
    unsigned char : 6;
    unsigned char pad6D[0xE7];
    int value;
};

extern "C" void fn_40_2DA58(Object* obj, unsigned int flag) {
    if (obj->state != 0) {
        fn_27_260604(obj, flag, obj->value);
        obj->flag = flag;
    }
}
