#pragma force_active on
struct Unknown {
    unsigned int pad0;
    unsigned int pad4;
    int field : 5;
};

extern "C" int fn_27_D371C(Unknown* obj) {
    return obj->field;
}
