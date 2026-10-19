#pragma force_active on
extern "C" {
void* fn_27_22A38(void*, short);
void* fn_27_1A2910(void*, short);
void __dl__FPv(void*);

void* fn_98_6D78(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_22A38(static_cast<char*>(object) + 0x34, memberDeleting);
        fn_27_1A2910(object, memberDeleting);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}
