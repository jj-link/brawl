#include <types.h>
#pragma force_active on

extern "C" void* fn_27_6F30C(void*);

struct fnInner {
    virtual void vf0();
    virtual fnInner* vf1();
};

struct Pad {
    u32 a;
    u32 b;
};

struct fnThird : Pad {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
};

extern "C" void fn_27_6CA10(fnInner* self) {
    fnInner* inner = *(fnInner**)((char*)self + 0x48);
    char* q = (char*)inner->vf1();
    void* a = fn_27_6F30C(q + 0x1c);
    void* b = *(void**)((char*)a + 0x44);
    b = *(void**)((char*)b + 0xd8);
    b = *(void**)((char*)b + 0x38);
    ((fnThird*)b)->vf40();
}
