#pragma force_active on
void operator delete(void*);
extern "C" void fn_121_CD5C(void*, short);

extern "C" void* fn_121_CDBC(void* object, short deleting) {
    if (object != 0) {
        fn_121_CD5C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
