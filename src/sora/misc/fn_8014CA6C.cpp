#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
u16 NETCalcCRC16(void* p, u32 len);
void* memcpy(void* dst, const void* src, u32 n);
void* memset(void* dst, int c, u32 n);
}

extern "C" void fn_8014CA6C(u8* self, void* src, u32 size) {
    u8* buf;
    u16 crc;

    self[0x8] = 1;
    if (size >= 0x2804) {
        memcpy(*(void**)self, src, 0x2804);
        buf = *(u8**)self;
        if (*(u16*)buf == 0x2804) {
            crc = *(u16*)(buf + 2);
            *(u16*)(buf + 2) = 0;
            if (crc == (u16)NETCalcCRC16(*(void**)self, 0x2804)) {
                self[0x8] = 0;
            }
        }
    }
    if (self[0x8] != 0) {
        memset(*(void**)self, 0, 0x2804);
    }
    self[0x9] = 1;
}
