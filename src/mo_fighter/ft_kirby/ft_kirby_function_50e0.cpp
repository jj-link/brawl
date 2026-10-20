#pragma force_active on
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_96_5068(void* object, short flag);

void operator delete(void*);

extern "C" void* fn_96_50E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0xB4, -1);
        if (object != 0) {
            fn_96_5068(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
