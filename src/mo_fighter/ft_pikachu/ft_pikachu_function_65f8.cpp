#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_565F0(void*, short);
void* fn_98_6664(void*, short);

void* fn_98_65F8(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_565F0(static_cast<char*>(object) + 0x14, memberDeleting);
        fn_98_6664(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
