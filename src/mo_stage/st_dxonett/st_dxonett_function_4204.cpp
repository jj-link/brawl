#pragma force_active on
struct Obj {
    char pad[0x160];
    unsigned char* flag;
};

extern "C" void fn_78_4204(Obj* obj) {
    *obj->flag = 1;
}
