#pragma force_active on
void operator delete(void*);
extern "C" void fn_116_1EC4(void*, short);
extern "C" void* fn_116_1F20(void*, short);

extern "C" void* fn_116_3E50(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short flag = 0;
        fn_116_1EC4(storage + 0x14, flag);
        fn_116_1F20(storage + 0x8, flag);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
