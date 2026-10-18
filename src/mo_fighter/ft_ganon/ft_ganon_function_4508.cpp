#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_109_4508(void* array, short release) {
    if (array != 0) {
        if (release > 0)
            __dl__FPv(array);
    }
    return array;
}

}
