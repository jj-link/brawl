#pragma force_active on
typedef unsigned long u32;

extern "C" {
extern float lbl_16_rodata_26C;
void printIndex__5MuMsgFUlUlPv(void* msg, u32 a, u32 b, void* c);
void setFrameVisible__8MuObjectFf(void* obj, float f);
}

extern "C" void fn_16_54D8(void* self) {
    char* p = (char*)self;
    printIndex__5MuMsgFUlUlPv(*(void**)(p + 0x154), 6, 11, *(void**)(p + 0x458));
    setFrameVisible__8MuObjectFf(*(void**)(p + 0x70), lbl_16_rodata_26C);
    *(u32*)(p + 0x3f0) = 30;
}
