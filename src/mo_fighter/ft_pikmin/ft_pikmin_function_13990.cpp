#pragma force_active on
extern "C" {
void* fn_113_11D54(void* object, short deleting);

void* fn_113_13990(void* p, short deleting) {
    if (p != 0) {
        fn_113_11D54(p, 0);
        if (deleting > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
