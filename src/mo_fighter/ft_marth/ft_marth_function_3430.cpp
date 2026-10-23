#pragma force_active on
void operator delete(void*);

extern "C" void fn_27_75E0C(void*, short);
extern "C" void fn_27_64930(void*, short);
extern "C" void* fn_106_1EE4(void*, short);

extern "C" void* fn_106_3430(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        fn_27_75E0C(storage + 0x4C, -1);
        if (storage + 0x20 != 0) {
            fn_27_64930(storage + 0x20, 0);
        }
        fn_106_1EE4(storage + 0x14, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
