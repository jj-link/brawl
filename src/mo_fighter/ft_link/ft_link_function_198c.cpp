#pragma force_active on
void operator delete(void*);

extern "C" {
void fn_27_57BA0(void*, short);
void fn_93_1A0C(void*, short);
void fn_93_1A68(void*, short);

void* fn_93_198C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_93_1A0C(storage + 0x14, 0);
        fn_93_1A68(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
