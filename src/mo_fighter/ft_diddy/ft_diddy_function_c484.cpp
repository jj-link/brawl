#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_C424(void* object, short deleting);
extern "C" void fn_115_C2EC(void* object, short deleting);

extern "C" void* fn_115_C484(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_C424(storage + 0x17C, -1);
        if (object != 0) {
            fn_115_C2EC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
