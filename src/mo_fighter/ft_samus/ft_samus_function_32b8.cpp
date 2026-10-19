#pragma force_active on
extern "C" void* fn_94_3314(void* object, short deleting);

extern "C" void* fn_94_32B8(void* p, short deleting) {
    if (p != 0) {
        fn_94_3314(p, 0);
        if (deleting > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
