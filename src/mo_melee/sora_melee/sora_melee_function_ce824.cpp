#pragma force_active on
struct Obj {
    unsigned int pad[2];
    unsigned int value;
};

extern "C" void fn_27_CE824(Obj *obj, unsigned int value) {
    obj->value = __rlwimi(obj->value, value, 26, 0, 5);
}
