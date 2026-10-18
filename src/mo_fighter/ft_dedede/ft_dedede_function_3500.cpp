#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_34A0(void*, short);

extern "C" void* fn_117_3500(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_34A0(storage + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
