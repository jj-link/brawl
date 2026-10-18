#pragma force_active on
extern "C" void fn_109_6790(void* object, int isNull);
extern "C" unsigned char lbl_109_data_16AC[];

struct Fn109Work {
    void* secondary;
    unsigned int reserved;
    void* primary;
    unsigned int arg0;
    unsigned int arg1;
    unsigned int arg2;
    unsigned int arg3;
    unsigned int arg4;
    unsigned int arg5;
};

extern "C" Fn109Work* fn_109_7978(
    Fn109Work* object,
    unsigned int arg0,
    unsigned int arg1,
    unsigned int arg2,
    unsigned int arg3,
    unsigned int arg4,
    unsigned int arg5
) {
    fn_109_6790(object, 0);

    object->primary = lbl_109_data_16AC;
    object->secondary = lbl_109_data_16AC + 8;
    object->arg0 = arg0;
    object->arg1 = arg1;
    object->arg2 = arg2;
    object->arg3 = arg3;
    object->arg4 = arg4;
    object->arg5 = arg5;

    return object;
}
