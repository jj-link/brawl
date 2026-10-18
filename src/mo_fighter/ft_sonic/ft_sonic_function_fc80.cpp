#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
void* fn_123_FC80(void* array, int release);
}

void* fn_123_FC80(void* array, int release) {
    if (array != 0) {
        if ((short)release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
