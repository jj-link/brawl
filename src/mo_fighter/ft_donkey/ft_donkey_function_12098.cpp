#pragma force_active on
extern "C" void* fn_92_3E20(void* object, short deleting);
extern "C" void* fn_92_3EA4(void* object, short deleting);
extern "C" void* fn_92_12134(void* object, short deleting);
extern "C" void* fn_92_3F04(void* object, short deleting);
extern "C" void* fn_92_402C(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

extern "C" void operator delete(void*);

extern "C" void* fn_92_12098(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_3E20(storage + 0x110, -1);
        fn_92_3EA4(storage + 0xfc, -1);
        fn_92_12134(storage + 0xec, -1);
        fn_92_3F04(storage + 0x48, -1);
        fn_92_402C(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
