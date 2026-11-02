#pragma force_active on

extern "C" {
extern unsigned char lbl_27_data_157E0[];
extern void* lbl_27_bss_5780;

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
void fn_27_22B194(void*, void*);
void fn_80010E50(void*, int);
void __dl__FPv(void*);
}

struct Inner {
    unsigned char pad[0x10];
    void* value;
};

struct Obj {
    unsigned char pad0[4];
    Inner* inner;
    unsigned char pad1[0x15];
    unsigned char flags;
    unsigned char pad2[2];
    void* vtable;
};

extern "C" Obj* fn_27_A6978(Obj* self, int deleting) {
    if (self) {
        self->vtable = lbl_27_data_157E0;
        if (self->inner) {
            if ((unsigned int)((self->flags >> 5) & 1) == 1) {
                if (!lbl_27_bss_5780) {
                    void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
                    if (p) {
                        p = fn_27_22A914(p);
                    }
                    lbl_27_bss_5780 = p;
                }
                fn_27_22B194(lbl_27_bss_5780, self->inner->value);
                self->flags &= ~0x20;
            }
            fn_80010E50(self->inner, 1);
            self->inner = 0;
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
