#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int : 12;
    unsigned int value : 6;
    unsigned int : 14;
};

extern "C" void fn_27_1A1824(Object* obj, unsigned int value) {
    obj->value = value;
}
