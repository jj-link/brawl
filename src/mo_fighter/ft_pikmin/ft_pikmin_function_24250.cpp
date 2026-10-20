#pragma force_active on
extern "C" {
void* fn_113_24210(void* ptr, short count);

void operator delete(void* ptr);

void* fn_113_24250(void* p, short n) {
    if (p != 0) {
        fn_113_24210(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
