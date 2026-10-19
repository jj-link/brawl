#pragma force_active on
void operator delete(void*);
extern "C" void fn_94_15CC4(void*, short);

extern "C" void* fn_94_15C00(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_94_15CC4(static_cast<unsigned char*>(object) + 4,
                        static_cast<short>(-1));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
