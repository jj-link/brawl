#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_1A20(void*, short);
extern "C" void* fn_118_1E00(void*, short);
extern "C" void* fn_118_1E9C(void*, short);
extern "C" void* fn_118_1FD4(void*, short);
extern "C" void* fn_27_125E20(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_1980(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_1A20(storage + 0x1048C, -1);
        fn_118_1E00(storage + 0xFFD4, -1);
        fn_118_1E9C(storage + 0xFF98, -1);
        fn_118_1FD4(storage + 0x194, -1);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
