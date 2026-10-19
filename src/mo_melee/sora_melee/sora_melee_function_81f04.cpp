#pragma force_active on
extern "C" {
void operator delete(void* p);

void* fn_27_81F04(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
