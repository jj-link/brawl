#pragma force_active on
#include <revolution/OS/OSTime.h>
extern "C" {
void netReport__FPCce(const char*, ...);
void fn_800C8F68(const char*, ...);
void fn_80140EBC(void*, int);
void fn_80143F7C(int, int);
void fn_8014B130(int);
extern unsigned char lbl_8059E742;
extern int lbl_805A03A8;
extern char lbl_8045E380[];
extern char lbl_8045E3A8[];
}
inline void update(unsigned char* self) {
    self[0x11] = 0;
    self[0x12] = 0;
    for (unsigned char j = 0; j < 4; j++) {
        if (*(signed char*)(self + 0xB0 + j * 0x20) != 0) {
            self[0x12] |= 1 << j;
            self[0x11]++;
        }
    }
}
extern "C" int fn_80141814(void* arg0) {
    unsigned char result;
    unsigned char* data;
    unsigned char* entry;
    unsigned char i;
    unsigned char* self = (unsigned char*)arg0;
    unsigned int tick = OSGetTick();
    entry = self + 0xB0;
    data = (unsigned char*)(*(unsigned int*)(self + 0x454)) + 0x14;
    result = 1;
    for (i = 0; i < 4; i++, entry += 0x20) {
        if (i != lbl_8059E742 && (signed char)entry[0] != 0 && data[i * 0x18] == 0) {
            result = 0;
            unsigned int stored = *(unsigned int*)(entry + 0x14);
            unsigned int clock = *(unsigned int*)0x800000F8;
            unsigned int threshold = ((clock >> 2) / 1000) * 60;
            if (tick - stored > threshold) {
                unsigned short counter = *(unsigned short*)(entry + 4);
                counter++;
                *(unsigned short*)(entry + 4) = counter;
                if (counter >= 0x1F4) {
                    netReport__FPCce(lbl_8045E380, i, stored);
                    fn_800C8F68(lbl_8045E3A8);
                    self[i * 0x20 + 0xB0] = 0;
                    update(self);
                    fn_80143F7C(lbl_805A03A8, i);
                    fn_8014B130(0xA);
                    *(unsigned short*)(entry + 4) = 0;
                }
                *(unsigned int*)(entry + 0x14) = tick;
                fn_80140EBC(self, 1);
            }
        }
    }
    return result;
}