#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_2158(void*, short);
void* fn_100_21F4(void*, short);
void* fn_100_2234(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

// Destroy the embedded module in reverse construction order, then the base.
extern "C" void* fn_100_272C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_2158(storage + 0xDC, destroy);
        fn_100_21F4(storage + 0xC0, destroy);
        fn_100_2234(storage + 0x14, destroy);
        if (object != 0) {
            fn_27_C7770(object, destroy);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
