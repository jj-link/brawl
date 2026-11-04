#include <types.h>
#pragma force_active on

extern "C" void fn_801AD2E0(const void* a, const void* b, void* fn);
extern "C" int fn_801AD260(const void* a, const void* b);
extern "C" bool fn_801AD2A0(const void* a, const void* b);

struct fn_801AD200_struct {
    int unk0;
    void* ptr0;
    void* ptr1;
    int unk12;
    int count0;
    int count1;
};

extern "C" void fn_801AD200(fn_801AD200_struct* arg0) {
    fn_801AD2E0(arg0->ptr0, (const void*)((char*)arg0->ptr0 + arg0->count0 * 4), (void*)fn_801AD260);
    fn_801AD2E0(arg0->ptr1, (const void*)((char*)arg0->ptr1 + arg0->count1 * 4), (void*)fn_801AD2A0);
}