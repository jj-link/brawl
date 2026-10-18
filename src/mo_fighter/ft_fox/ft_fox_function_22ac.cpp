#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_97_22AC(void* param_1, short param_2) {
    if (param_1 != 0 && param_2 > 0) {
        __dl__FPv(param_1);
    }
    return param_1;
}

}
