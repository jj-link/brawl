#include <gf/gf_pad_status.h>
#pragma force_active on

extern "C" {
extern void* g_gfPadSystem;

void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, gfPadStatus*);
void fn_5_11924(void*, gfPadStatus*, int);
int fn_16_998(void*, gfPadStatus*, char*, int, int);
void* memcpy(void*, const void*, unsigned long);
unsigned long strlen(const char*);
void fn_800B92D8(void*, unsigned long, char*, unsigned long);
int fn_800B5854(void*, int, int, int, int);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, unsigned long, unsigned char, unsigned char, unsigned char, unsigned char);
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
void fn_16_AF8(void*);
void setFrameNode__8MuObjectFf(void*, float);
}

struct MsgObj {
    virtual void n00();
    virtual void n01();
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07();
    virtual void n08();
    virtual void n09();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13(void*);
};

extern "C" void fn_5_C4E0(void* input) {
    char* self = (char*)input;
    gfPadStatus status;
    char* str;
    int index, size, mode;

    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xF0, &status);
    fn_5_11924(self, &status, 1);

    if (*(int*)(self + 0x40) == 14) {
        str = self + 0xC45AA;
        index = 0;
        size = 0x41;
        mode = 2;
    } else {
        str = self + 0xC45EB;
        index = 1;
        size = 0x51;
        mode = 4;
    }

    switch (fn_16_998(self + 0xC4660, &status, self + 0xC46F5, 1, 1)) {
    case 0:
        memcpy(str, self + 0xC46F5, size);
    case 1:
        if (strlen(str) != 0)
            fn_800B92D8(*(void**)(self + 0xC464C), index, str, strlen(str));
        ((MsgObj*)*(void**)(self + 0x7D68C))
            ->n13(*(void**)((char*)*(void**)(self + 0x7D65C) + 0xC));
        fn_800B5854(*(void**)(self + 0x7D654), mode, 0x11, 1, 0);
        setFontColor__5MuMsgFUlUcUcUcUc(*(void**)(self + 0xC4648), 2, 0xFF, 0xFF, 0xFF, 0xFF);
        printIndex__5MuMsgFUlUlPv(*(void**)(self + 0xC4648), 2, 3, 0);
        *(int*)(self + 0x40) = 13;
        fn_16_AF8(self + 0xC4660);
        break;
    case 2:
        strlen(self + 0xC46F5);
        fn_800B92D8(*(void**)(self + 0xC464C), index, self + 0xC46F5, strlen(self + 0xC46F5));
        setFrameNode__8MuObjectFf(*(void**)(self + 0x7D65C), (float)*(s32*)(self + 0xC46E4));
        break;
    }
}
