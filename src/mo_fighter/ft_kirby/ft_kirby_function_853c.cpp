#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_1F74(void*, short);
extern "C" void* fn_96_5EE4(void*, short);

extern "C" void* fn_96_853C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_1F74(storage + 0x20, 0);
        fn_96_5EE4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
