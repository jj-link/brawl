#pragma force_active on
void operator delete(void*);
extern "C" void fn_125_70B4(void*, short);
extern "C" void fn_125_3FB8(void*, short);

extern "C" void* fn_125_7048(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_70B4(storage + 0x24, -1);
        fn_125_3FB8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
