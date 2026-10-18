#pragma force_active on
extern "C" {
void* fn_98_3650(void*, short);
void __dl__FPv(void*);

void* fn_98_35F0(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_3650(static_cast<char*>(object) + 4, memberDeleting);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
