#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_57BA0(void*, short);
void fn_95_2040(void*, short);
void fn_95_209C(void*, short);
}

extern "C" void* fn_95_1FC0(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        short zero = 0;
        fn_95_2040(storage + 0x14, zero);
        fn_95_209C(storage + 8, zero);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
