#include <gf/gf_task.h>
#pragma force_active on
extern "C" {
extern char lbl_10_data_BB0[];
extern char lbl_10_data_C10[];
struct RO { float a, b, c, d; };
extern const RO lbl_10_rodata_7D0;
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, gfTask::Category, int, int, bool);
}
#pragma push
#pragma opt_propagation off
extern "C" void* fn_10_197F4(unsigned char* p) {
    const RO* r = &lbl_10_rodata_7D0;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_10_data_BB0, gfTask::Category_Menu, 15, 8, true);
    *(void**)(p+0x3c)=lbl_10_data_C10;
    *(int*)(p+0x40)=0; *(int*)(p+0x44)=0; *(int*)(p+0x48)=0; *(int*)(p+0x4c)=0;
    *(int*)(p+0x7c)=0; *(int*)(p+0x80)=0;
    *(int*)(p+0x9c)=0; *(int*)(p+0xa0)=0; *(int*)(p+0xa4)=0; *(int*)(p+0xa8)=0; *(int*)(p+0xac)=0; *(int*)(p+0xb0)=0;
    p[0xc4]=0; *(int*)(p+0xc8)=0; *(float*)(p+0xcc)=r->c;
    p[0xd0]=0; *(int*)(p+0xd4)=0; *(int*)(p+0xd8)=0; p[0xdc]=0;
    p[0x2c]&=~2;
    *(float*)(p+0x90)=r->b; *(float*)(p+0x94)=r->b; *(float*)(p+0x98)=r->d;
    *(float*)(p+0x84)=r->b; *(float*)(p+0x88)=r->b; *(float*)(p+0x8c)=r->d;
    *(float*)(p+0xb4)=r->b; *(float*)(p+0xb8)=r->b; *(float*)(p+0xbc)=r->b; *(float*)(p+0xc0)=r->b;
    *(int*)(p+0x50)=0; *(int*)(p+0x54)=0; *(int*)(p+0x58)=0; *(int*)(p+0x5c)=0; *(int*)(p+0x60)=0; *(int*)(p+0x64)=0; *(int*)(p+0x68)=0; *(int*)(p+0x6c)=0; *(int*)(p+0x70)=0; *(int*)(p+0x74)=0; *(int*)(p+0x78)=0;
    return p;
}
#pragma pop