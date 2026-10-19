#pragma force_active on
extern "C" {
void fn_100_1267C(void*, short);
void* fn_100_1293C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_1260C(char* object, short deleting) {
    if (object != 0) {
        fn_100_1267C(object + 0x19e8, -1);
        fn_100_1293C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
