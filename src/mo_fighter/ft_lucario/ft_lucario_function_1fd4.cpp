#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_2058(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_118_2910(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_1FD4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_2058(storage + 0xE7F8, -1);
        fn_27_C74E8(storage + 0xE7E8, -1);
        fn_118_2910(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
