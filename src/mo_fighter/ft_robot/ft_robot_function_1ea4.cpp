#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_57BA0(void*, short);
void fn_120_1F24(void*, short);
void fn_120_1F80(void*, short);
}

extern "C" void* fn_120_1EA4(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_120_1F24(storage + 0x14, 0);
        fn_120_1F80(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
