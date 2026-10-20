#pragma force_active on
extern "C" void* fn_109_96B4(void* object, short deleting);
extern "C" void* fn_109_4BBC(void* object, short deleting);
extern "C" void* fn_109_4C2C(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_109_4B44(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_96B4(storage + 0xE0, -1);
        fn_109_4BBC(storage + 0x30, -1);
        fn_109_4C2C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
