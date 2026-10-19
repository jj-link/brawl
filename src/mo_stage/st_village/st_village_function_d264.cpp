#pragma force_active on
extern "C" {
void fn_70_20FC(void* p, int n);
void* fn_70_D264(void* p, int n);
}

extern "C" void* fn_70_D264(void* p, int n) {
    if (p != 0) {
        fn_70_20FC(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
