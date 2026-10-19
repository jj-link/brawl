#pragma force_active on
extern "C" void fn_63_2C40(void* p, int x);

extern "C" {
void* fn_63_5E90(void* p, int n);
}

void* fn_63_5E90(void* p, int n) {
    if (p) {
        fn_63_2C40(p, 0);
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
