#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_2C28(void*, short);
extern "C" void* fn_113_2CAC(void*, short);
extern "C" void* fn_113_2CC54(void*, short);
extern "C" void* fn_113_3F04(void*, short);
extern "C" void* fn_113_2CCB0(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_113_2CBB8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_2C28(storage + 0x148, -1);
        fn_113_2CAC(storage + 0x134, -1);
        fn_113_2CC54(storage + 0x104, -1);
        fn_113_3F04(storage + 0x60, -1);
        fn_113_2CCB0(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
