#pragma force_active on
extern "C" {
void* fn_94_4928(void*, short);
void* fn_94_49AC(void*, short);
void* fn_94_50CC(void*, short);
void* fn_94_5128(void*, short);
void* fn_94_5B40(void*, short);
void* fn_27_C74E8(void*, short);

void operator delete(void*);

void* fn_94_5030(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_94_4928(p + 0xe04, -1);
        fn_94_49AC(p + 0xdf0, -1);
        fn_94_50CC(p + 0x930, -1);
        fn_94_5128(p + 0xbc, -1);
        fn_94_5B40(p + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0)
            operator delete(object);
    }
    return object;
}
}
