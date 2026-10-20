#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_CCD4(void* object, short deleting);
extern "C" void* fn_108_CBA4(void* object, short deleting);

extern "C" void* fn_108_CD34(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_CCD4(storage + 0x94, -1);
        if (object != 0) {
            fn_108_CBA4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
