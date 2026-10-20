#pragma force_active on
extern "C" {
void __dt__17grGimmickWarpZoneFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_40_37E50(void* object, int shouldDelete) {
    if (object != 0) {
        __dt__17grGimmickWarpZoneFv(object, 0);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
