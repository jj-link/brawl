#pragma force_active on
extern "C" {
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_2_24CC8(void* object, int shouldDelete) {
    if (object) {
        __dt__6gfTaskFv(object, 0);
        if (shouldDelete > 0)
            __dl__FPv(object);
    }
    return object;
}
