#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_4B53C(void*, short);
void fn_27_19C45C(void*, short);
}

extern "C" void* fn_100_6100(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_4B53C(storage + 0x17C, destroy);
        fn_27_19C45C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
