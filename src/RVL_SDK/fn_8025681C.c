#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

void fn_8025681C(void* self) {
    u8* base = (u8*)self;
    void* ptr = *(void**)(base + 0x6C);
    if (((u8*)ptr)[0x72] == 2) {
        u16 val = *(u16*)(base + 0x98);
        if (val != 0) {
            *(u16*)(base + 0x98) = val - 1;
        }
        if (*(u16*)(base + 0x98) == 0) {
            *(u8*)(base + 0x24) = 1;
        }
    }
}
