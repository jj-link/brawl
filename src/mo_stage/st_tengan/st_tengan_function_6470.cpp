#pragma force_active on
struct grYakumono;

extern "C" void __dt__10grYakumonoFv(grYakumono*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_60_6470(grYakumono* object, int shouldDelete)
{
    if (object != 0) {
        __dt__10grYakumonoFv(object, 0);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
