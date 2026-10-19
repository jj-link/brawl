#pragma force_active on
struct FZeroObject {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x14C];
    void* allocation;
};

extern "C" {
extern unsigned char lbl_61_data_36D8[];
void __dl__FPv(void*);
void fn_61_2384(FZeroObject*, int);

FZeroObject* fn_61_D464(FZeroObject* self, int deleteFlag) {
    if (self) {
        self->vtable = lbl_61_data_36D8;
        if (self->allocation) {
            __dl__FPv(self->allocation);
        }
        self->allocation = 0;
        fn_61_2384(self, 0);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
