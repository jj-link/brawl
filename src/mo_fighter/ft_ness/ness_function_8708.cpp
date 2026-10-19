#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_4B53C(void*, short);
void fn_27_19C45C(void*, short);
}

extern "C" void* fn_101_8708(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_4B53C(static_cast<unsigned char*>(object) + 0x17C, memberDeleting);
        fn_27_19C45C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
