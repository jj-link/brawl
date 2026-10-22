#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_800FC3D8(void*);
void fn_800FC3E4(void*);
extern void* lbl_805A0350;
}

struct Flags8 {
    unsigned char b0 : 1;
    unsigned char rest : 7;
};

extern "C" void fn_8010F310() {
    unsigned char* self = (unsigned char*)__nw__FUlQ25Heaps8HeapType(0x1C, 0x28);
    if (self != 0) {
        ((Flags8*)self)->b0 = 0;
        *(int*)(self + 0x8) = 0;
        *(int*)(self + 0xC) = 0;
        *(int*)(self + 0x10) = 0;
        __construct_array(self + 0x14, (void (*)(void*))fn_800FC3D8, (void (*)(void*))fn_800FC3E4, 4, 2);
        *(int*)(self + 0x8) = 0;
        *(int*)(self + 0xC) = 0;
        lbl_805A0350 = self;
    }
}
