#pragma force_active on
extern "C" {
void fn_801C6B14(void*);
void fn_801C710C(void*, void*);
extern char lbl_80466778[];

void* fn_801C0CA0(void* self) {
    fn_801C6B14(self);
    *(int*)((char*)self + 0x108) = 0;
    *(void**)self = lbl_80466778;
    fn_801C710C((char*)self + 0x10C, &lbl_80466778);
    return self;
}
}
