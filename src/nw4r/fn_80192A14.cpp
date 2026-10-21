#pragma force_active on

struct Obj {
    void* value;
};

extern "C" void fn_801D7718(Obj*, void*);
extern "C" void fn_801D7774(Obj*, void*);

extern "C" void fn_80192A14(Obj** p, int flag) {
    Obj* obj = *p;
    void* value = obj->value;

    if (flag != 0) {
        fn_801D7718(obj, value);
    } else {
        fn_801D7774(obj, value);
    }
}
