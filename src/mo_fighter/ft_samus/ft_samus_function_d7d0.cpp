#pragma force_active on
void operator delete(void*);
extern "C" void fn_94_D770(void*, short);

extern "C" void* fn_94_D7D0(void* object, short deleting) {
    if (object != 0) {
        fn_94_D770(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
