#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Owner {
    char pad[0x10];
    u32 value;
};

struct Object {
    u32 unk0;
    Owner* owner;
    u8 pad[0x15];
    u8 bits : 2;
    u8 flags : 1;
    u8 rest : 5;
};

extern "C" void* lbl_27_bss_5780;
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_22A914(void*);
extern "C" void fn_27_22B194(void*, u32);

extern "C" void fn_27_A7838(Object* self) {
    if (self->flags == 1) {
        if (!lbl_27_bss_5780) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
            if (p)
                p = fn_27_22A914(p);
            lbl_27_bss_5780 = p;
        }
        fn_27_22B194(lbl_27_bss_5780, self->owner->value);
        self->flags = 0;
    }
}
