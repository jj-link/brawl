#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
void __dla__FPv(void*);
void fn_8015A978(void*, int, int);
void fn_8015AAA4(void);
void fn_8015AE80(void*, int);
void* memset(void*, int, u32);
}

extern "C" void fn_80159968(u8* self) {
    fn_8015AAA4();
    fn_8015AE80(self, 0);
    fn_8015A978(self, 1, 0);
    *(u32*)(self + 0x1C) = 0;
    memset(*(void**)(self + 0x14), 0, 0xBF4);
    if (*(void**)(self + 0x18) != 0) {
        __dla__FPv(*(void**)(self + 0x18));
        *(void**)(self + 0x18) = 0;
    }
    *(u32*)(self + 0x20) = 0;
}
