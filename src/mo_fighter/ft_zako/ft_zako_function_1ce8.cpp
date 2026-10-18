#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_57BA0(void*, short);
void fn_126_1D68(void*, short);
void fn_126_1DC4(void*, short);
}

extern "C" void* fn_126_1CE8(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_126_1D68(storage + 0x14, 0);
        fn_126_1DC4(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
