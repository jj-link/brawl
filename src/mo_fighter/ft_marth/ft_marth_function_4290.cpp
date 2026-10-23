#pragma force_active on
extern "C" {
void* fn_27_150488(void*, short);
void* fn_106_4310(void*, short);
void* fn_27_199A54(void*, short);
void __dl__FPv(void*);
}

// Complete-object destructor for the Marth fighter-module member.
extern "C" void* fn_106_4290(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_150488(storage + 0x5B8, destroy);
        fn_106_4310(storage + 0x584, destroy);
        if (object != 0) {
            fn_27_199A54(object, destroy);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
