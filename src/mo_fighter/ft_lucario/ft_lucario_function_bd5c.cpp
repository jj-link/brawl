#pragma force_active on
extern "C" void* fn_118_BD00(void*, short);
void operator delete(void*);

extern "C" void* fn_118_BD5C(void* object, short deleting) {
    if (object != 0) {
        fn_118_BD00(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
