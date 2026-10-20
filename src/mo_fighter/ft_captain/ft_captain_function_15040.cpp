#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_3898(void*, short);
void* fn_100_150D0(void*, short);
void* fn_100_1515C(void*, short);
void* fn_100_151E8(void*, short);
void* fn_100_15274(void*, short);
}

extern "C" void* fn_100_15040(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_3898(storage + 0x4B0, destroy);
        fn_100_150D0(storage + 0x384, destroy);
        fn_100_1515C(storage + 0x258, destroy);
        fn_100_151E8(storage + 0x12C, destroy);
        fn_100_15274(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
