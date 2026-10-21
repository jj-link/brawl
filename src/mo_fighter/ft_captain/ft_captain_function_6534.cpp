#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_13C90(void*, short);
void* fn_100_65E8(void*, short);
void* fn_27_21038(void*, short);
void* fn_100_6654(void*, short);
void* fn_100_66B0(void*, short);
void* fn_100_4480(void*, short);
void* fn_100_670C(void*, short);
void* fn_100_6768(void*, short);
}

extern "C" void* fn_100_6534(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_13C90(storage + 0x224, destroy);
        fn_100_65E8(storage + 0x1E8, destroy);
        fn_27_21038(storage + 0x1D8, destroy);
        fn_100_6654(storage + 0x1B8, destroy);
        fn_100_66B0(storage + 0x198, destroy);
        fn_100_4480(storage + 0x160, destroy);
        fn_100_670C(storage + 0xC4, destroy);
        fn_100_6768(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
