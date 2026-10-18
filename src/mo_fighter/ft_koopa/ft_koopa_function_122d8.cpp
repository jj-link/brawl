#pragma force_active on
extern "C" void* fn_102_3BC8(void* object, short deleting);
extern "C" void* fn_102_3C4C(void* object, short deleting);
extern "C" void* fn_102_12374(void* object, short deleting);
extern "C" void* fn_102_45A8(void* object, short deleting);
extern "C" void* fn_102_4FC0(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_102_122D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_3BC8(storage + 0xDE0, -1);
        fn_102_3C4C(storage + 0xDCC, -1);
        fn_102_12374(storage + 0x930, -1);
        fn_102_45A8(storage + 0xBC, -1);
        fn_102_4FC0(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
