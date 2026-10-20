#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_E6FC(void* object, short deleting);
extern "C" void fn_113_E5C4(void* object, short deleting);

extern "C" void* fn_113_E75C(void* object, short deleting) {
    if (object != 0) {
        fn_113_E6FC(static_cast<unsigned char*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_113_E5C4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
