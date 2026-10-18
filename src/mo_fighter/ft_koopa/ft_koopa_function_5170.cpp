#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_150488(void*, short);
void* fn_102_51F0(void*, short);
void* fn_27_199A54(void*, short);
}

extern "C" void* fn_102_5170(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_150488(storage + 0x5B8, destroy);
        fn_102_51F0(storage + 0x584, destroy);
        if (object != 0) {
            fn_27_199A54(object, destroy);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
