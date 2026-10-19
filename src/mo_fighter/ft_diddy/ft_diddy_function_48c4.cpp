#pragma force_active on
extern "C" {
void* fn_115_1F4C(void*, short);
void* fn_115_1EF0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_115_48C4(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short zero = 0;
        fn_115_1F4C(storage + 0x20, zero);
        if (object) fn_115_1EF0(storage + 0x8, zero);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
