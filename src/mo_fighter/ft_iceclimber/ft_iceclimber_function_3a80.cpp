#pragma force_active on
extern "C" {
void* fn_27_63EBC(void*, short);
void __dl__FPv(void*);

void* fn_105_3A80(void* object, short deleting) {
    if (object) {
        fn_27_63EBC(object, (short)-1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
