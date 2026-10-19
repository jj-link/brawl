#pragma force_active on
extern "C" {
void fn_27_B21D0(void*, short);
void fn_27_CB4A0(void*, short);
void operator delete(void*);
}

extern "C" void* fn_100_5BE4(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_B21D0(storage + 0x50, destroy);
        if (object != 0) {
            fn_27_CB4A0(object, destroy);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
