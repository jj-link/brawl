#pragma force_active on
extern "C" {
void fn_109_1F10(void*, short);
void fn_109_1EB4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_109_10834(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_1F10(storage + 0x20, 0);
        if (object) fn_109_1EB4(storage + 0x8, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
