#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_150488(void*, short);
void* fn_27_199A54(void*, short);
void* fn_122_9C3C(void*, short);
}

extern "C" void* fn_122_9BBC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_150488(members + 0x5B8, memberDeleting);
        fn_122_9C3C(members + 0x584, memberDeleting);
        if (object != 0) {
            fn_27_199A54(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
