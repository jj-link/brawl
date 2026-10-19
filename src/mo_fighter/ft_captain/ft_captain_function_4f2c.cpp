#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_100_1F14(void*, short);
void* fn_100_3C20(void*, short);
}

extern "C" void* fn_100_4F2C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = 0;
        fn_100_1F14(storage + 0x20, destroy);
        fn_100_3C20(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
