#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" int strcmp(const char*, const char*);
extern char lbl_8059E14C;

struct Copy65 {
    u8 bytes[65];
};

extern "C" void fn_800C71EC(u8* self, void* arg1, const char* arg2) {
    s32 r = strcmp(arg2, &lbl_8059E14C);
    if ((u32)(-r | r) >> 31) {
        *(Copy65*)(self + 0x15D) = *(const Copy65*)arg2;
        *(void**)(self + 0x380) = arg1;
        *(u8**)(self + 0x384) = self + 0x15D;
        *(s32*)(self + 0x350) = 8;
    }
}
