#pragma force_active on
extern "C" {
void fn_80108798(void* p);

void fn_80107834(void* p) {
    void* v = *(void**)((char*)p + 0x60);
    if (v != 0) {
        fn_80108798(v);
    }
}
}
