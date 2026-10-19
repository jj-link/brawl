#pragma force_active on
extern "C" {
typedef int s32;

void exit__6gfTaskFv(void*);

s32 fn_1_ADC0(void* self) {
    void* task = *(void**)((char*)self + 8);
    exit__6gfTaskFv(task);
    *(void**)((char*)self + 8) = 0;
    return 0;
}
}
