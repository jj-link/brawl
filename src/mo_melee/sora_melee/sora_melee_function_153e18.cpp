#pragma force_active on
extern "C" {
void operator delete(void* p);

void* fn_27_153E18(void* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
}
