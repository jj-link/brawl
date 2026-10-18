#pragma force_active on
extern "C" void* __dl__FPv(void*);
extern "C" void* fn_92_3E20(void*, short);
extern "C" void* fn_92_3EA4(void*, short);
extern "C" void* fn_92_5214(void*, short);
extern "C" void* fn_92_5270(void*, short);
extern "C" void* fn_92_5C88(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_92_5178(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_3E20(storage + 0xE24, -1);
        fn_92_3EA4(storage + 0xE10, -1);
        fn_92_5214(storage + 0x930, -1);
        fn_92_5270(storage + 0xBC, -1);
        fn_92_5C88(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
