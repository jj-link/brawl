#pragma force_active on
extern "C" {
void* fn_98_BBE8(void*, short);
void* __dl__FPv(void*);

void* fn_98_BC48(void* object, int deleting) {
    if (object) {
        fn_98_BBE8((char*)object + 4, (short)-1);
        if ((short)deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
