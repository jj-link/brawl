#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
void* memset(void*, int, unsigned long);
void fn_80225454(void*);
unsigned long utf8to16__7MessageFPwPCc(void* dst, const char* src);

extern const char lbl_16_data_36E0[];
extern char lbl_16_data_36F4[];
extern const char* lbl_16_data_870;

typedef struct {
    unsigned char f0:1;
    unsigned char f1:1;
    unsigned char f2:1;
    unsigned char f3:1;
    unsigned char f4:1;
    unsigned char f5:1;
    unsigned char f6:1;
    unsigned char f7:1;
} BitByte;

void* fn_16_6C64() {
    wchar_t buf[24];
    char* obj = (char*)__nw__FUlQ25Heaps8HeapType(0xDC, 0x2A);
    if (obj) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(obj, lbl_16_data_36E0, 8, 0xF, 8, true);
        *(char**)(obj + 0x3C) = lbl_16_data_36F4;
        *(int*)(obj + 0x40) = 0;
        *(int*)(obj + 0x44) = 0;
        *(int*)(obj + 0x48) = 0;
        *(int*)(obj + 0x4C) = 0;
        *(int*)(obj + 0xD0) = 0;
        *(int*)(obj + 0xD4) = 0;
        *(char*)(obj + 0xD8) = 0;
        ((BitByte*)(obj + 0x2C))->f6 = 0;
        memset(obj + 0x50, 0, 0x40);
        memset(obj + 0x90, 0, 0x40);
    }
    utf8to16__7MessageFPwPCc(buf, lbl_16_data_870);
    fn_80225454(buf);
    return obj;
}
}
