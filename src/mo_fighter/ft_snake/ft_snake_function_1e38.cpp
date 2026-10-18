#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_57BA0(void*, short);
void fn_122_1EB8(void*, short);
void fn_122_1F14(void*, short);
}

extern "C" void* fn_122_1E38(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_122_1EB8(storage + 0x14, 0);
        fn_122_1F14(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
