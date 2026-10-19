#pragma force_active on
extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_71_28E0(void* object, int shouldDelete)
{
    if (object != 0) {
        if (object != 0) {
            __dt__10grYakumonoFv(object, 0);
        }
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
