#include <string.h>

#pragma force_active on

extern "C" {
extern const char lbl_81_data_0[];
extern const char lbl_81_data_3C4[];
extern const float lbl_81_rodata_0;

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void* fn_81_4E8(void*);
void* fn_81_518(void*, int);
void __construct_array(void*, void* (*)(void*), void (*)(void*), unsigned long, int);
}

#define B(x) (*(unsigned char*)(p + (x)))
#define F(x) (*(float*)(p + (x)))
#define I(x) (*(int*)(p + (x)))
#define SIX(q) \
    (q)[0] = lbl_81_rodata_0; \
    (q)[1] = lbl_81_rodata_0; \
    (q)[2] = lbl_81_rodata_0; \
    (q)[3] = lbl_81_rodata_0; \
    (q)[4] = lbl_81_rodata_0; \
    (q)[5] = lbl_81_rodata_0

extern "C" void* fn_81_A4(void* self) {
    char* p = (char*)self;

    __ct__7stMeleeFPCcQ26Stages11srStageKind(self, lbl_81_data_0, 0x31);

    struct Node {
        Node* next;
        Node* prev;
    };

    Node* node = (Node*)(p + 0x364);
    node->next = 0;
    node->prev = 0;
    *(const char**)(p + 0x3C) = lbl_81_data_3C4;
    I(0x360) = 0;
    node->next = node;
    node->prev = node;

    __construct_array(p + 0xAA0, fn_81_4E8,
                      (void (*)(void*))fn_81_518, 0x10, 5);

    B(0x1D8) = 0;
    F(0x1DC) = lbl_81_rodata_0;
    memset(p + 0x1E0, 0, 0x18);
    B(0x1F8) = 0;
    memset(p + 0x1FC, 0, 12);
    memset(p + 0x21C, 0, 12);
    memset(p + 0x208, 0, 12);
    F(0x214) = lbl_81_rodata_0;
    B(0x218) = 0;

    unsigned int i = 0;
    for (int count = 0; count < 2; ++count) {
        unsigned char index = i;
        i += 6;
        float* q = (float*)(p + 0x230 + index * 0x18);
        SIX(q);
        p[index + 0x350] = 12;
        SIX(q + 6);
        p[index + 0x351] = 12;
        SIX(q + 12);
        p[index + 0x352] = 12;
        SIX(q + 18);
        p[index + 0x353] = 12;
        SIX(q + 24);
        p[index + 0x354] = 12;
        SIX(q + 30);
        p[index + 0x355] = 12;
    }

    B(0x228) = 0;
    F(0x22C) = lbl_81_rodata_0;
    B(0x35C) = 12;

    char* r;
    for (unsigned char i = 0; i < 30; i++) {
        r = p + i * 0x3C;
        *(unsigned char*)(r + 0x374) = 10;
        float* q = (float*)(r + 0x378);
        SIX(q);
        q[6] = lbl_81_rodata_0;
        q[7] = lbl_81_rodata_0;
        q[8] = lbl_81_rodata_0;
        q[9] = lbl_81_rodata_0;
        q[10] = lbl_81_rodata_0;
        r[0x3a4] = 0;
        *(float*)(r + 0x3a8) = lbl_81_rodata_0;
        r[0x3ac] = 0;
    }

    B(0x36C) = 0;
    F(0x370) = lbl_81_rodata_0;
    memset(p + 0xA7C, 0, 0x1E);
    B(0xA9A) = 0;
    B(0xA9B) = 0;
    B(0xA9D) = 0;

    I(0xAA8) = -1;
    B(0xAAC) = 0;
    I(0xAB8) = -1;
    B(0xABC) = 0;
    I(0xAC8) = -1;
    B(0xACC) = 0;
    I(0xAD8) = -1;
    B(0xADC) = 0;
    I(0xAE8) = -1;
    B(0xAEC) = 0;
    B(0xAF0) = 0;

    char* r2;
    for (unsigned char i = 0; i < 6; i++) {
        r2 = p + i * 0x34;
        r2[0xB00] = 10;
        float* q = (float*)(r2 + 0xB04);
        SIX(q);
        q[6] = lbl_81_rodata_0;
        q[7] = lbl_81_rodata_0;
        q[8] = lbl_81_rodata_0;
        q[9] = lbl_81_rodata_0;
        q[10] = lbl_81_rodata_0;
        r2[0xB30] = 0;
        r2[0xB31] = 0;
    }

    B(0xAF1) = 0;
    F(0xAF4) = lbl_81_rodata_0;
    I(0xAF8) = 0;
    I(0xAFC) = 0;
    B(0xC38) = 0;
    return self;
}
