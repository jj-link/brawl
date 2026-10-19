#pragma force_active on
extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_56_1014(void* object, int deleting) {
    if (object != 0) {
        __dt__10grYakumonoFv(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
