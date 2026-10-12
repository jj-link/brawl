#include <new>

extern "C" {
void* fn_98_3AEC(void*, short);
void* fn_98_2138(void*, short);
void* fn_98_21D4(void*, short);
void* fn_98_2214(void*, short);
void* fn_27_C7770(void*, short);
}

#pragma always_inline on
#pragma inline_depth(8)

// Destruction of each embedded aggregate retains both its own and its base's null guards.
static inline void destroyAggregate(char* aggregate) {
    if (aggregate) {
        short deleting = -1;
        fn_98_2138(aggregate + 0xdc, deleting);
        fn_98_21D4(aggregate + 0xc0, deleting);
        fn_98_2214(aggregate + 0x14, deleting);
        if (aggregate) fn_27_C7770(aggregate, deleting);
    }
}

static inline void destroyStorage(char* storage) {
    fn_98_3AEC(storage + 0x4b0, static_cast<short>(-1));
    destroyAggregate(storage + 0x384);
    destroyAggregate(storage + 0x258);
    destroyAggregate(storage + 0x12c);
    destroyAggregate(storage);
}

extern "C" void* fn_98_398C(void* object, short deleting) {
    if (object) {
        destroyStorage(static_cast<char*>(object));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
