#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_108_6E48(void* object, short deleteFlag);

extern "C" void* fn_108_6DD0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* bytes = static_cast<unsigned char*>(object);
        fn_27_D2904(bytes + 0xB4, -1);
        if (object != 0) {
            fn_108_6E48(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
