#pragma force_active on
extern "C" {

extern void __dl__FPv(void*);

void* fn_105_1D90(void* object, short release) {
    if (object != 0 && release > 0) {
        __dl__FPv(object);
    }
    return object;
}

}
