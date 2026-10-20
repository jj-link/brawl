#pragma force_active on
extern "C" float fn_27_1120CC(void** param) {
    struct Obj {
        char pad[0x4AC];
        float value;
    };
    Obj* obj = *(Obj**)param;
    return obj->value;
}
