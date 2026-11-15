#pragma force_active on

#include <ut/ut_list.h>

struct ResBase { char pad[0x14]; };
class ftDataTaskResource : public ResBase {
public:
    virtual void isNull();
    virtual void at(s32 index);
};

extern "C" {
extern unsigned char lbl_27_data_2BAC0[];
extern unsigned char lbl_27_data_2BB78[];
extern unsigned char lbl_27_data_2BAE8[];
extern void* lbl_27_bss_31F8;

void fn_27_6FE94(void* self, int v);
void* fn_27_14523C(void* self);
void* fn_27_141588(void* self, int shouldDelete);
void __construct_array(void* base, void* ctor, void* dtor, unsigned long size, unsigned long count);
}

extern "C" void* fn_27_141448(unsigned char* p) {
    *(void**)(p + 0x0) = lbl_27_data_2BAC0;
    *(void**)(p + 0x10) = lbl_27_data_2BB78;
    p[0xc] = 0;
    p[0x14] = 0;
    *(void**)(p + 0x18) = lbl_27_data_2BAE8;
    fn_27_6FE94(p + 0x20, 0);
    *(int*)(p + 0x28) = 0xff;
    *(int*)(p + 0x2c) = 0;
    *(int*)(p + 0x30) = -1;
    __construct_array(p + 0x38, (void*)fn_27_14523C, (void*)fn_27_141588, 0x34, 0x50);
    *(int*)(p + 0x1078) = -1;
    p[0x10a0] = 1;
    lbl_27_bss_31F8 = p;
    *(int*)(p + 0x108c) = 0;
    *(int*)(p + 0x1088) = 0;
    *(int*)(p + 0x1090) = 0;
    *(int*)(p + 0x1098) = 0;
    *(int*)(p + 0x1094) = 0;
    *(int*)(p + 0x109c) = 0;
    *(int*)(p + 0x1080) = 0;
    *(int*)(p + 0x107c) = 0;
    *(int*)(p + 0x1084) = 0;
    ((ftDataTaskResource*)(p + 4))->at(0);

    s32 offset;
    s32 i = 0;
    offset = 0;
    do {
        ((ftDataTaskResource*)((unsigned long)(p + 0x38) + offset))->at(0);
        ((utList*)(p + 0x107c))->addTail((utListNode*)((unsigned long)p + offset + 0x38));
        i++;
        offset += 0x34;
    } while (i < 0x50);
    return p;
}
