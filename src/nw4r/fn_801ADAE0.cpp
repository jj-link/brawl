#include <types.h>
#pragma force_active on

extern "C" void fn_801AD2E0(const void* a, const void* b, void* fn);
extern "C" void fn_801ADB40();
extern "C" void fn_801ADBD0();

struct fn_801ADAE0_struct {
    int unk0;
    void* ptr0;
    void* ptr1;
    int unk12;
    int count0;
    int count1;
};

extern "C" void fn_801ADAE0(fn_801ADAE0_struct* arg0) {
    fn_801AD2E0(arg0->ptr0, (const void*)((char*)arg0->ptr0 + arg0->count0 * 4), (void*)fn_801ADB40);
    fn_801AD2E0(arg0->ptr1, (const void*)((char*)arg0->ptr1 + arg0->count1 * 4), (void*)fn_801ADBD0);
}
