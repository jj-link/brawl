#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_112_3C40(void*, short);

extern "C" void* fn_112_ED74(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x9c, -1);
        fn_27_21038(storage + 0x88, -1);
        fn_112_3C40(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
