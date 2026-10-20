#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
void start__18gfGameFrameCounterFv(void*);
u32 getFrameCounter__10wnemSimpleFl(void*, s32);
void wnemReport__FPCce(const char*, ...);
extern char lbl_41_data_47D4[];

void SetLifeLimit__10wnemSimpleFl(char* self, s32 life) {
    u32 fc = getFrameCounter__10wnemSimpleFl(self, 0);
    s32 val = (s32)fc + life;
    *(s32*)(self + 0x21D0) = val;
    if (val > 0) {
        if (*(unsigned char*)(self + 0x21B9) == 0) {
            *(unsigned char*)(self + 0x21B9) = 1;
            start__18gfGameFrameCounterFv(self + 0x221C);
        }
        wnemReport__FPCce(lbl_41_data_47D4, getFrameCounter__10wnemSimpleFl(self, 0), *(s32*)(self + 0x21D0));
    }
}
}
