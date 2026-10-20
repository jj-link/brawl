#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_3A14(void*, short);
extern "C" void* fn_119_118A8(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_119_11904(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_3A14(storage + 0x6C, -1);
        fn_119_118A8(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
