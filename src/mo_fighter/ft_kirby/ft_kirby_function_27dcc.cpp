#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_277BC(void*, short);
extern "C" void fn_96_27D44(void*, short);

extern "C" void* fn_96_27DCC(void* object, short deleting) {
    if (object != 0) {
        fn_96_277BC(static_cast<unsigned char*>(object) + 0x1FC4, -1);
        fn_96_27D44(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
