#pragma force_active on
typedef unsigned short u16;
typedef unsigned long u32;

extern "C" {
void fn_802FAD24(char* arg0, char* arg1) {
    u16 idx = *(u16*)(arg1 + 0x22);
    if (idx != 0xFFFF) {
        u32* table = *(u32**)(arg0 + 0x40);
        *(u32*)((char*)table + (u32)idx * 4) = 0;
        *(u16*)(arg1 + 0x22) = 0xFFFF;
    }
}
}
