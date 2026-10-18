#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_57BA0(void*, short);
extern "C" void* fn_118_1F1C(void*, short);
extern "C" void* fn_118_1F78(void*, short);

extern "C" void* fn_118_1E9C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_118_1F1C(storage + 0x14, 0);
        fn_118_1F78(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
