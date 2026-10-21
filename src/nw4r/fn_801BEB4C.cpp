#pragma force_active on
extern "C" void fn_801C6B14(void* self);
extern "C" void fn_801C710C(void* a, void* b);
extern "C" char lbl_804666B8[];

extern "C" void* fn_801BEB4C(void* self) {
    fn_801C6B14(self);
    *(int*)self = (int)&lbl_804666B8;
    fn_801C710C((void*)((char*)self + 0x108), &lbl_804666B8);
    *(unsigned char*)((char*)self + 0x188) = 0;
    return self;
}
