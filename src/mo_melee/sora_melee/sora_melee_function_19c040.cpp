#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int field : 3;
    unsigned int rest : 29;
};

extern "C" void fn_27_19C040(Object* obj, unsigned int value) {
    obj->field = value;
}
