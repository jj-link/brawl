#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_209C(void*, short);
extern "C" void* fn_95_3DE4(void*, short);

extern "C" void* fn_95_6340(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_209C(storage + 0x20, 0);
        fn_95_3DE4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
