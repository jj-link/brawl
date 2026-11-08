#include <types.h>
#pragma force_active on
extern "C" {
extern void* lbl_27_bss_B8;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_4FAB4(void*);
s32 fn_27_3786C(s32);
void fn_27_3627C(void*, s32);
void fn_27_37880(void*, s32, float, float);
void fn_27_36768(void*, s32, s32);
void* fn_27_36028(void*, s32, s32, void*);
u32 fn_27_389E0(void*, s32, s32, s32, s32, u32, u32, float);
void fn_27_36A8C(void*);
}
class soCollisionAttackModuleImpl {
public:
    virtual ~soCollisionAttackModuleImpl();
    virtual void fn_27_39AA4();
    virtual void fn_27_39C34();
    virtual void fn_27_39C90();
    virtual void fn_27_39D10();
    virtual void fn_27_39D80();
    virtual void fn_27_39E30();
    virtual void fn_27_39EF4();
    virtual void fn_27_3A0C4();
    virtual s32 fn_27_3A270();
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
};
extern "C" void fn_27_3B1A8(void* self, void* vec1, s32 index, void* vec2, float f0, float f1) {
    unsigned char* base = (unsigned char*)self;
    u32 flags = *(u32*)(base + 0x9c);
    if (((flags >> 29) & 1) == 1) {
        float b;
        float a;
        a = *(float*)vec2;
        b = *(float*)((unsigned char*)vec2 + 4);
        *(float*)(base + 0x40) = a;
        *(float*)(base + 0x44) = b;
    }
    float d;
    float c;
    c = *(float*)vec1;
    d = *(float*)((unsigned char*)vec1 + 4);
    *(float*)(base + 0x38) = c;
    *(float*)(base + 0x3c) = d;
    *(float*)(base + 0x60) = f0;
    *(s32*)(base + 0x88) = fn_27_3786C(index);
    *(float*)(base + 0x8c) = f1;
    flags = *(u32*)(base + 0x9c);
    if (((flags >> 30) & 1) != 1) {
        s32 i;
        s32 val;
        u32 flag;
        flag = 0;
        val = (*(soCollisionAttackModuleImpl**)((unsigned char*)(*(void**)((unsigned char*)(*(void**)(base + 0x28)) + 0xd8)) + 0x44))->fn_27_3A270();
        s32 cnt = (*(Object_vptr_0**)(base + 0x64))->slot3();
        i = 0;
        while (i < cnt) {
            fn_27_3627C(base + 0x68, i);
            fn_27_37880(base + 0x68, i, *(float*)vec1, f1);
            fn_27_36768(base + 0x68, val, i);
            i++;
        }
        cnt = (*(Object_vptr_0**)(base + 0x30))->slot3();
        s32 val2;
        unsigned char* item;
        s32 j = 0;
        while (j < cnt) {
            item = (unsigned char*)(*(Object_vptr_0**)(base + 0x30))->slot1(j);
            if (*(s32*)item) {
                void* p2 = *(void**)((unsigned char*)(*(void**)(base + 0x28)) + 0xd8);
                val2 = *(s32*)((unsigned char*)p2 + 4);
                void* res = fn_27_36028(base + 0x68, j, *(s32*)(item + 0x88), p2);
                float amount = *(float*)(base + 0x60);
                u32 r = fn_27_389E0(item, val2, (s32)res, *(s32*)(base + 0x88), 0, 0, 0, amount);
                if (r == 1)
                    flag = 1;
            }
            j++;
        }
        if (flag == 1 || *(unsigned char*)(base + 0x7a) == 1) {
            if (!lbl_27_bss_B8) {
                void* mem = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
                if (mem)
                    mem = fn_27_4FAB4(mem);
                lbl_27_bss_B8 = mem;
            }
            s32 bss_flag = *(s32*)((unsigned char*)lbl_27_bss_B8 + 0xb4);
            if (!(bss_flag & 1) || !((*(s32*)(base + 0x9c) >> 28) & 1))
                fn_27_36A8C(base + 0x68);
        }
    }
    *(u32*)(base + 0x9c) |= 0x08000000;
}