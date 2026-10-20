#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_2158(void*, short);
void* fn_100_21F4(void*, short);
void* fn_100_2234(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

namespace {
struct ParameterBaseLifetime {
    inline ~ParameterBaseLifetime() { fn_27_C7770(this, static_cast<short>(-1)); }
};
}

extern "C" void* fn_100_23E4(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_2158(storage + 0xDC, destroy);
        fn_100_21F4(storage + 0xC0, destroy);
        fn_100_2234(storage + 0x14, destroy);
        reinterpret_cast<ParameterBaseLifetime*>(object)->~ParameterBaseLifetime();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
