struct MarioMantleParameterAdapter {
    void* vtable;
    unsigned char baseFields[4];
    int parameter;
    int index;
};
extern "C" {
void* fn_91_1A70(void*, int);
extern unsigned char lbl_91_data_7EFC[];
MarioMantleParameterAdapter* fn_91_FE04(MarioMantleParameterAdapter* object, int parameter) {
    fn_91_1A70(object, 0);
    object->vtable = lbl_91_data_7EFC;
    object->parameter = parameter;
    object->index = -1;
    return object;
}
}
