#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_BD5C(void*, short);

extern "C" void* fn_118_BDBC(void* object, short deleting) {
    if (object != 0) {
        fn_118_BD5C(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
