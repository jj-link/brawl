#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_CE6C(void* object, short deleting);
extern "C" void fn_108_CD34(void* object, short deleting);

extern "C" void* fn_108_CECC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_CE6C(storage + 0xEC, -1);
        if (object != 0) {
            fn_108_CD34(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
