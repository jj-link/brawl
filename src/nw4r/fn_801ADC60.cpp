#include <types.h>
#pragma force_active on

extern "C" void fn_801AD2E0(const void* a, const void* b, void* fn);

struct fn_801ADC60_struct {
    int unk0;
    void* ptr4;
    void* ptr8;
    int unkC;
    int count10;
    int count14;
};

extern "C" void fn_801ADC60(fn_801ADC60_struct* arg0, void* arg1, void* arg2) {
    fn_801AD2E0(arg0->ptr4, (const void*)((char*)arg0->ptr4 + arg0->count10 * 4), arg1);
    fn_801AD2E0(arg0->ptr8, (const void*)((char*)arg0->ptr8 + arg0->count14 * 4), arg2);
}
