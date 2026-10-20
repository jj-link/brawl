#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1FE4(void*, short);
extern "C" void fn_121_4E68(void*, short);

extern "C" void* fn_121_4EE0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1FE4(storage + 0x244, -1);
        if (object != 0) {
            fn_121_4E68(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
