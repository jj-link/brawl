#pragma force_active on
extern "C" void fn_117_66FC(void*, int);
extern "C" unsigned char lbl_117_data_925C[];

struct Object {
    void* table;
    unsigned char baseFlag;
    unsigned char flag : 1;
    unsigned char unused : 7;
    unsigned char value;
};

extern "C" void* fn_117_20F0C(Object* object, int arg) {
    fn_117_66FC(object, arg);
    object->flag = arg == 0;
    object->value = 0;
    object->table = lbl_117_data_925C;
    return object;
}
