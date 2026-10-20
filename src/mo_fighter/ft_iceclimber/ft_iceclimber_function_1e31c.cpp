#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_3814(void*, short);
extern "C" void* fn_105_3880(void*, short);
extern "C" void* fn_105_390C(void*, short);
extern "C" void* fn_105_3998(void*, short);
extern "C" void* fn_105_1E3AC(void*, short);

extern "C" void* fn_105_1E31C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_3814(storage + 0x4B0, -1);
        fn_105_3880(storage + 0x384, -1);
        fn_105_390C(storage + 0x258, -1);
        fn_105_3998(storage + 0x12C, -1);
        fn_105_1E3AC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
