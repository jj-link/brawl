#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_3DEC(void*, short);
void* fn_100_67E0(void*, short);
void* fn_27_CD934(void*, short);
}

extern "C" void* fn_100_6768(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_3DEC(storage + 0xAC, destroy);
        fn_100_67E0(storage + 0x20, destroy);
        fn_27_CD934(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
