#pragma force_active on
void operator delete(void*);
extern "C" void fn_102_A728(void* object, short deleting);
extern "C" void* fn_102_A860(void* object, short deleting);

extern "C" void* fn_102_A8C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_A860(storage + 0xEC, -1);
        if (object != 0) {
            fn_102_A728(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
