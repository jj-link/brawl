#pragma force_active on
struct fn_27_C51E8_Obj {
    int pad[2];
    unsigned int top : 2;
    unsigned int rest : 30;
};

extern "C" void fn_27_C51E8(fn_27_C51E8_Obj* obj, unsigned int v) {
    obj->top = v;
}
