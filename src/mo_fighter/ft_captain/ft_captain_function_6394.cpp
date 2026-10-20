#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_100_640C(void*, short);
void* fn_100_646C(void*, short);
}

extern "C" void* fn_100_6394(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_B5324(storage + 0x30, destroy);
        fn_100_640C(storage + 0x18, destroy);
        fn_100_646C(storage + 0x04, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
