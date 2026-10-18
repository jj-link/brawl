#pragma force_active on
void operator delete(void*);
extern "C" void fn_94_1579C(void*, short);

extern "C" void* fn_94_1573C(void* object, short deleting) {
    if (object != 0) {
        fn_94_1579C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
