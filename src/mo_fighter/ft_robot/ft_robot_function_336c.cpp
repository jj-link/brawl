#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_33E4(void* object, short deleting);
extern "C" void fn_120_34A4(void* object, short deleting);

extern "C" void* fn_120_336C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_33E4(storage + 0x7E78, -1);
        if (object != 0) {
            fn_120_34A4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
