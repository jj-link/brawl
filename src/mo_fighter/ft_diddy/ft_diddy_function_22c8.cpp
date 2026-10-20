#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_2334(void* object, short flag);
extern "C" void* fn_115_2190(void*, short);

extern "C" void* fn_115_22C8(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        fn_115_2334(static_cast<unsigned char*>(object) + 0x50, flag);
        fn_115_2190(object, flag);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
