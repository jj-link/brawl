#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;

extern "C" void fn_41_28F74(void*, u32, u32);
extern "C" void fn_41_B8D4(void*, void*, void*, void*, void*);

extern "C" void fn_41_40794(void* self, void* p2, void* p3, void* p4, void* p5) {
    if (*(s32*)((u8*)self + 0xAC) == 0x20) {
        switch (*(s32*)p2) {
        case 0x13FE:
            fn_41_28F74((u8*)self + 0x1108, 1, 0x4D);
            *((u8*)p2 + 4) = 1;
            break;
        default:
            break;
        }
    }
    fn_41_B8D4(self, p2, p3, p4, p5);
}
