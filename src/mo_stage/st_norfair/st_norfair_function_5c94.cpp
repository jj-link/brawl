#pragma force_active on

extern "C" {
void* fn_54_5BEC(void* p, int n);
void __destroy_arr(void* p, void* dtor, unsigned long size, unsigned long count);
void __dl__FPv(void* p);

void* fn_54_5C94(void* arr, int count) {
    void* p = arr;
    if (p != 0) {
        __destroy_arr((void*)((char*)p + 0xC), (void*)fn_54_5BEC, 8, 6);
        if (count > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
