#pragma force_active on
extern "C" void* fn_27_97968(void*, short);
extern "C" void* fn_27_1CCCC(void*, short);
extern "C" void* fn_100_30AC(void*, short);
extern "C" void* fn_27_CBF58(void*, short);
extern "C" void __dl__FPv(void*);

namespace {
struct Base {
    inline ~Base() { fn_27_CBF58(this, static_cast<short>(-1)); }
};
}

extern "C" void* fn_100_39BC(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_97968(storage + 0x58, destroy);
        fn_27_1CCCC(storage + 0x48, destroy);
        fn_100_30AC(storage + 0x3C, destroy);
        reinterpret_cast<Base*>(object)->~Base();
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
