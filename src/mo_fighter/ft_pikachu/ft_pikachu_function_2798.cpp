#pragma force_active on
extern "C" {
void* fn_98_2138(void*, short);
void* fn_98_21D4(void*, short);
void* fn_98_2214(void*, short);
void* fn_98_2830(void*, short);
void* fn_27_1A60DC(void*, short);
}
void operator delete(void*);

static inline void destroyBase(void* object, short deleting) {
    if (object) fn_27_1A60DC(object, deleting);
}

extern "C" void* fn_98_2798(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_2138(static_cast<char*>(object) + 0x9e4, memberDeleting);
        fn_98_21D4(static_cast<char*>(object) + 0x9c8, memberDeleting);
        fn_98_2214(static_cast<char*>(object) + 0x91c, memberDeleting);
        fn_98_2830(static_cast<char*>(object) + 0x48c, memberDeleting);
        destroyBase(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
