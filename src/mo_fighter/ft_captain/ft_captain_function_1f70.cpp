#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_1FF4(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_100_28AC(void*, short);
}

extern "C" void* fn_100_1F70(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_100_1FF4(members + 0xA890, destroy);
        fn_27_C74E8(members + 0xA880, destroy);
        fn_100_28AC(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
