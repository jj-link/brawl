#pragma force_active on
extern "C" {
void operator delete(void* p);

void* fn_72_3CA8(void* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
}
