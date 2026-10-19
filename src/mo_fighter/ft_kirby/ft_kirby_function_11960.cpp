#pragma force_active on
extern "C" void fn_96_118A0(void*, short);
void operator delete(void*);

extern "C" void* fn_96_11960(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_96_118A0(static_cast<unsigned char*>(object) + 4,
                        static_cast<short>(-1));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
