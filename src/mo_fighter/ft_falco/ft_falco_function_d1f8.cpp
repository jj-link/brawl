#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_D198(void* object, short deleting);
extern "C" void fn_108_D060(void* object, short deleting);

extern "C" void* fn_108_D1F8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_D198(storage + 0x17C, -1);
        if (object != 0) {
            fn_108_D060(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
