#include <types.h>
#pragma force_active on

struct FlagByte { unsigned char high : 1; unsigned char rest : 7; };
struct Elem { u32 flag : 1; u32 val : 16; u32 rest : 15; s32 a; s32 b; s32 c; };

extern "C" {
extern char lbl_8049E550[];
extern char lbl_8045C4BC[];
extern char lbl_6_data_478[];
extern char lbl_6_data_510[];
extern char lbl_6_data_560[];
extern char lbl_6_data_660[];
void addTail__6utListFP10utListNode(void* list, void* node);
void removeExist__6utListFP10utListNode(void* list, void* node);
void __construct_array(void* p, void (*ctor)(u32*), void (*dtor)(u32*), s32 size, s32 count);
char* strcat(char* dst, const char* src);
void fn_800B96E8(void* p, s32 v);
void fn_6_8C4(u32* p);
void fn_6_8D0(u32* p);

void* fn_6_278(void* self, s32 arg1, s32 arg2, s32 arg3) {
    char* s = (char*)self;
    char* d560 = lbl_6_data_560;

    *(void**)(s + 0x0) = 0;
    *(void**)(s + 0x1D08) = lbl_6_data_478;
    *(void**)(s + 0xC) = 0;
    char* a = s + 0x4;
    *(void**)(a + 0x0) = 0;
    *(void**)(a + 0x4) = 0;
    addTail__6utListFP10utListNode(lbl_8049E550, a);
    *(void**)(a + 0x8) = lbl_8049E550;
    *(void**)(a + 0xC) = d560;
    *(void**)(s + 0x30) = lbl_8045C4BC;
    *(void**)(s + 0x10) = lbl_8045C4BC + 8;
    *(void**)(s + 0x1C) = 0;
    *(void**)(s + 0x14) = 0;
    *(void**)(s + 0x18) = 0;
    char* b = s + 0x14;
    addTail__6utListFP10utListNode(lbl_8049E550, b);
    *(void**)(b + 0x8) = lbl_8049E550;
    *(void**)(b + 0xC) = lbl_6_data_510;
    *(void**)(b + 0x10) = 0;
    *(u8*)(b + 0x14) = 0;
    *(u8*)(s + 0x2C) = 0;
    removeExist__6utListFP10utListNode(lbl_8049E550, b);

    char* nn;
    char* k;
    char* e;
    char* d;
    char* c = s + 0x38;
    *(void**)(s + 0x1C) = 0;
    *(void**)(s + 0x34) = 0;
    *(void**)(s + 0x40) = 0;
    *(void**)(s + 0x38) = 0;
    *(void**)(s + 0x3C) = 0;
    addTail__6utListFP10utListNode(lbl_8049E550, c);
    *(void**)(c + 0xC) = d560;
    *(void**)(c + 0x8) = lbl_8049E550;
    *(void**)(s + 0x64) = lbl_8045C4BC;
    *(void**)(s + 0x44) = lbl_8045C4BC + 8;
    *(void**)(s + 0x50) = 0;
    *(void**)(s + 0x48) = 0;
    *(void**)(s + 0x4C) = 0;
    d = s + 0x48;
    addTail__6utListFP10utListNode(lbl_8049E550, d);
    *(void**)(d + 0x8) = lbl_8049E550;
    *(void**)(d + 0xC) = lbl_6_data_510;
    *(void**)(d + 0x10) = 0;
    *(u8*)(d + 0x14) = 0;
    *(u8*)(s + 0x60) = 0;
    removeExist__6utListFP10utListNode(lbl_8049E550, d);

    e = s + 0x6C;
    *(void**)(s + 0x50) = 0;
    *(void**)(s + 0x68) = 0;
    *(void**)(s + 0x74) = 0;
    *(void**)(s + 0x6C) = 0;
    *(void**)(s + 0x70) = 0;
    addTail__6utListFP10utListNode(lbl_8049E550, e);
    *(void**)(e + 0xC) = d560;
    *(void**)(e + 0x8) = lbl_8049E550;
    *(void**)(s + 0x98) = lbl_8045C4BC;
    *(void**)(s + 0x78) = lbl_8045C4BC + 8;
    *(void**)(s + 0x84) = 0;
    *(void**)(s + 0x7C) = 0;
    *(void**)(s + 0x80) = 0;
    char* f = s + 0x7C;
    addTail__6utListFP10utListNode(lbl_8049E550, f);
    *(void**)(f + 0x8) = lbl_8049E550;
    *(void**)(f + 0xC) = lbl_6_data_510;
    *(void**)(f + 0x10) = 0;
    *(u8*)(f + 0x14) = 0;
    *(u8*)(s + 0x94) = 0;
    removeExist__6utListFP10utListNode(lbl_8049E550, f);

    k = s + 0xA0;
    *(void**)(s + 0x84) = 0;
    *(void**)(s + 0x9C) = 0;
    *(void**)(s + 0xA8) = 0;
    *(void**)(s + 0xA0) = 0;
    *(void**)(s + 0xA4) = 0;
    addTail__6utListFP10utListNode(lbl_8049E550, k);
    *(void**)(k + 0xC) = d560;
    *(void**)(k + 0x8) = lbl_8049E550;
    *(void**)(s + 0xCC) = lbl_8045C4BC;
    *(void**)(s + 0xAC) = lbl_8045C4BC + 8;
    *(void**)(s + 0xB8) = 0;
    *(void**)(s + 0xB0) = 0;
    *(void**)(s + 0xB4) = 0;
    char* m = s + 0xB0;
    addTail__6utListFP10utListNode(lbl_8049E550, m);
    *(void**)(m + 0x8) = lbl_8049E550;
    *(void**)(m + 0xC) = lbl_6_data_510;
    *(void**)(m + 0x10) = 0;
    *(u8*)(m + 0x14) = 0;
    *(u8*)(s + 0xC8) = 0;
    removeExist__6utListFP10utListNode(lbl_8049E550, m);

    nn = s + 0xD4;
    *(void**)(s + 0xB8) = 0;
    *(void**)(s + 0xD0) = 0;
    *(void**)(s + 0xDC) = 0;
    *(void**)(s + 0xD4) = 0;
    *(void**)(s + 0xD8) = 0;
    addTail__6utListFP10utListNode(lbl_8049E550, nn);
    *(void**)(nn + 0xC) = d560;
    *(void**)(nn + 0x8) = lbl_8049E550;
    *(void**)(s + 0x100) = lbl_8045C4BC;
    *(void**)(s + 0xE0) = lbl_8045C4BC + 8;
    *(void**)(s + 0xEC) = 0;
    *(void**)(s + 0xE4) = 0;
    *(void**)(s + 0xE8) = 0;
    char* p = s + 0xE4;
    addTail__6utListFP10utListNode(lbl_8049E550, p);
    *(void**)(p + 0x8) = lbl_8049E550;
    *(void**)(p + 0xC) = lbl_6_data_510;
    *(void**)(p + 0x10) = 0;
    *(u8*)(p + 0x14) = 0;
    *(u8*)(s + 0xFC) = 0;
    removeExist__6utListFP10utListNode(lbl_8049E550, p);

    *(void**)(s + 0xEC) = 0;
    *(s32*)(s + 0x180) = arg1;
    *(s32*)(s + 0x19C) = arg2;
    *(s32*)(s + 0x1A0) = 0;
    __construct_array(s + 0x1A4, fn_6_8C4, fn_6_8D0, 0x10, 2);
    *(s32*)(s + 0x1C4) = arg3;

    char* p2 = s + 0x1C8;
    do {
        *(u8*)p2 = 0;
        strcat(p2, lbl_6_data_660);
        *(s32*)(p2 + 0x44) = 0x3D;
        p2 += 0x68;
    } while (p2 < s + 0x1AF8);

    *(s32*)(s + 0x1AF8) = 0;
    *(u8*)(s + 0x1AFC) = 0;
    strcat(s + 0x1AFC, lbl_6_data_660);
    *(s32*)(s + 0x1B40) = 0;
    fn_800B96E8(s + 0x1B44, 0xFF);

    *(s32*)(s + 0x1BF0) = 0;
    *(s32*)(s + 0x1BF4) = 0;
    *(u8*)(s + 0x1BF8) = 0;
    *(s32*)(s + 0x1BFC) = 0;
    *(s32*)(s + 0x1C00) = 7;
    ((FlagByte*)(s + 0x1C04))->high = 1;
    ((FlagByte*)(s + 0x1C14))->high = 1;
    ((FlagByte*)(s + 0x1C24))->high = 1;
    ((FlagByte*)(s + 0x1C34))->high = 1;
    ((FlagByte*)(s + 0x1C44))->high = 1;
    ((FlagByte*)(s + 0x1C54))->high = 1;
    ((FlagByte*)(s + 0x1C64))->high = 1;
    { Elem* el = (Elem*)(s + 0x1C04); el[0].val = 0; el[0].a = 0; el[0].b = 0; el[0].c = 0; el[1].val = 0; el[1].a = 0; el[1].b = 0; el[1].c = 0; el[2].val = 0; el[2].a = 0; el[2].b = 0; el[2].c = 0; el[3].val = 0; el[3].a = 0; el[3].b = 0; el[3].c = 0; el[4].val = 0; el[4].a = 0; el[4].b = 0; el[4].c = 0; el[5].val = 0; el[5].a = 0; el[5].b = 0; el[5].c = 0; el[6].val = 0; el[6].a = 0; el[6].b = 0; el[6].c = 0; }
    *(u8*)(s + 0x1C74) = 0;
    *(u8*)(s + 0x1C75) = 0;
    *(s32*)(s + 0x1C78) = 0;
    *(s32*)(s + 0x1C7C) = 0;
    *(s32*)(s + 0x1C88) = 0;
    *(s32*)(s + 0x1C80) = 0;
    *(s32*)(s + 0x1C84) = 0;
    char* g = s + 0x1C80;
    addTail__6utListFP10utListNode(lbl_8049E550, g);
    *(s32*)(g + 0x10) = 0;
    *(void**)(g + 0x8) = lbl_8049E550;
    *(void**)(g + 0xC) = lbl_6_data_510;
    *(u8*)(g + 0x14) = 0;

    char* h = s + 0x1C98;
    *(s32*)(s + 0x1CA0) = 0;
    *(s32*)(s + 0x1C98) = 0;
    *(s32*)(s + 0x1C9C) = 0;
    addTail__6utListFP10utListNode(lbl_8049E550, h);
    *(void**)(h + 0x8) = lbl_8049E550;
    *(void**)(h + 0xC) = lbl_6_data_510;
    *(s32*)(h + 0x10) = 0;
    *(u8*)(h + 0x14) = 0;

    char* i2 = s + 0x1CB0;
    *(s32*)(s + 0x1CB8) = 0;
    *(s32*)(s + 0x1CB0) = 0;
    *(s32*)(s + 0x1CB4) = 0;
    addTail__6utListFP10utListNode(lbl_8049E550, i2);
    *(void**)(i2 + 0x8) = lbl_8049E550;
    *(void**)(i2 + 0xC) = lbl_6_data_510;
    *(s32*)(i2 + 0x10) = 0;
    *(u8*)(i2 + 0x14) = 0;

    char* jj = s + 0x1CC8;
    *(s32*)(s + 0x1CD0) = 0;
    *(s32*)(s + 0x1CC8) = 0;
    *(s32*)(s + 0x1CCC) = 0;
    addTail__6utListFP10utListNode(lbl_8049E550, jj);
    *(void**)(jj + 0x8) = lbl_8049E550;
    *(void**)(jj + 0xC) = lbl_6_data_510;
    *(s32*)(jj + 0x10) = 0;
    *(u8*)(jj + 0x14) = 0;
    *(s32*)(s + 0x1CE0) = 0;
    *(s32*)(s + 0x1CE4) = 0;
    *(s32*)(s + 0x1CE8) = 0;
    *(u8*)(s + 0x1CEC) = 0;
    *(u8*)(s + 0x1CED) = 0;
    *(u8*)(s + 0x1CEE) = 0;
    *(s32*)(s + 0x1CF0) = 0;
    *(s32*)(s + 0x1CF8) = 7;
    *(s32*)(s + 0x1CFC) = 0;
    *(s32*)(s + 0x1D00) = 0;
    *(s32*)(s + 0x1D04) = 0;

    char* q = s;
    s32 ctr = 0x1F;
    while (ctr--) {
        *(s32*)(q + 0x104) = 0;
        q += 4;
    }

    *(s32*)(s + 0x184) = 0;
    *(s32*)(s + 0x188) = 0;
    *(s32*)(s + 0x18C) = 0;
    *(s32*)(s + 0x190) = 0;
    *(s32*)(s + 0x194) = 0;
    *(s32*)(s + 0x198) = 0;
    fn_800B96E8(s + 0x1B44, 0xF0);
    return self;
}
}
