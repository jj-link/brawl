#pragma force_active on
extern "C" {
extern void* fn_113_2068(void*, short);
extern void* fn_113_3774(void*, short);
extern void __dl__FPv(void*);
}

extern "C" void* fn_113_3704(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_2068(storage + 0x99EC, -1);
        fn_113_3774(storage + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
