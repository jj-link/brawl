#pragma force_active on
extern "C" {
void* fn_98_5034(void*, short);
void __dl__FPv(void*);

void* fn_98_4FD4(void* object, int deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_5034(static_cast<char*>(object) + 4, memberDeleting);
        if (static_cast<short>(deleting) > 0) __dl__FPv(object);
    }
    return object;
}
}
