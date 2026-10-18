#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_2C28(void* object, short deleting);
extern "C" void* fn_113_2CAC(void* object, short deleting);
extern "C" void* fn_113_49A4(void* object, short deleting);
extern "C" void* fn_113_4A00(void* object, short deleting);
extern "C" void* fn_113_5418(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

extern "C" void* fn_113_4908(void* object, short deleting) {
    if (object != 0) {
        fn_113_2C28(static_cast<unsigned char*>(object) + 0xdc4, -1);
        fn_113_2CAC(static_cast<unsigned char*>(object) + 0xdb0, -1);
        fn_113_49A4(static_cast<unsigned char*>(object) + 0x934, -1);
        fn_113_4A00(static_cast<unsigned char*>(object) + 0xc0, -1);
        fn_113_5418(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
