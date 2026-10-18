#pragma force_active on
extern "C" {
void* __dt__21ftExtendParamAccesserFv(void*, short);
void __dl__FPv(void*);

void* fn_91_A30C(void* object, short deleting) {
    if (object == 0) {
        goto done;
    }
    if (object == 0) {
        goto delete_check;
    }

    __dt__21ftExtendParamAccesserFv(object, 0);

delete_check:
    if (deleting > 0) {
        __dl__FPv(object);
    }

done:
    return object;
}
}
