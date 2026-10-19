#pragma force_active on
extern "C" {
extern void* fn_102_33C0(void*, short);
extern void* fn_102_4104(void*, short);
extern void __dl__FPv(void*);

void* fn_102_4098(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_33C0(storage + 0x5EA0, -1);
        fn_102_4104(storage + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
