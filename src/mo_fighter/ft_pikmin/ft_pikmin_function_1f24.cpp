#pragma force_active on
extern "C" void* fn_113_1F80(void* object, short deleting);
void operator delete(void* p);

extern "C" void* fn_113_1F24(void* p, short deleting) {
    if (p != 0) {
        fn_113_1F80(p, 0);
        if (deleting > 0) {
            operator delete(p);
        }
    }
    return p;
}
