#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_93100(void*, short);
void* fn_92_3298(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);
}

extern "C" void* fn_92_3210(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_93100(storage + 0x10000 - 0x5F8C, destroy);
        fn_92_3298(storage + 0x7C, destroy);
        fn_27_19F4C4(storage + 0x20, destroy);
        fn_27_1A55B0(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
