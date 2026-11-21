#include <types.h>
#pragma force_active on
extern "C" {
void fn_27_1A558C(void*, int);
void fn_27_19F434(void*, int, int);
void* fn_27_1484BC(void*, int, void*);
void* fn_27_14858C(void*, int, void*);
void fn_27_3120B8(void*, int, void*, void*);
void fn_27_352878(void*, int, void*, void*);
void fn_27_92F10(void*, void*, void*, void*, void*);
void fn_108_98E4(void*, void*);
void fn_108_9978(void*, void*);
extern unsigned char g_ftCommonDataAccesser;
extern char lbl_108_data_10C8[];
extern char lbl_108_data_12FC[];
extern char lbl_108_data_1388[];
extern char lbl_108_data_1590[];
extern char lbl_108_data_1760[];
extern char lbl_108_data_17F0[];
extern char lbl_108_data_1880[];
extern char lbl_108_data_1910[];
extern char lbl_108_data_19A0[];
extern char lbl_108_data_1BD8[];
extern char lbl_108_data_1D3C[];
extern char lbl_108_data_1DC8[];
extern char lbl_108_data_1F8C[];
extern char lbl_108_data_2038[];
extern char lbl_108_data_20C4[];
extern char lbl_108_data_B28[];
extern char lbl_108_data_EAC[];
}

struct Pair { int a, b; };
struct Args { Pair* pair; void* data; };
struct Flags {
    bool unused;
    bool flag;
};
struct Locals {
    Pair unusedPair;
    Pair pair;
    Args args;
};

inline void* getData(void* fighter) {
    return *(void**)(*(char**)((char*)fighter + 0xd8) + 0xc0);
}

extern "C" void* fn_108_9678(void* arg0, void* arg1) {
    char* self = (char*)arg0;
    char* r28;
    char* r27;
    char* sub;
    char* r24;
    char* r23;
    char* r22;
    char* x;
    char* y;
    char* w;
    Locals l1;
    Locals l2;
    Flags f1;
    Flags f2;

    fn_27_1A558C(arg0, 0);
    fn_27_19F434(self + 0x20, 5, 0);
    r28 = self + 0x7C;
    *(void**)r28 = lbl_108_data_B28;
    *(void**)(r28 + 4) = lbl_108_data_B28 + 0x10;
    r27 = r28 + 8;
    *(void**)r27 = lbl_108_data_1F8C;
    sub = r27 + 4;
    *(void**)sub = lbl_108_data_2038;
    r24 = sub + 8;
    *(void**)r24 = lbl_108_data_20C4;

    f1.unused = false;
    f1.flag = false;
    l1.unusedPair.a = 0;
    int kind1 = l1.unusedPair.b = 0x13;
    void* data1 = getData(arg1);
    l1.pair.a = l1.unusedPair.a;
    l1.pair.b = l1.unusedPair.b;
    l1.args.pair = &l1.pair;
    l1.args.data = data1;
    void* common1 = fn_27_1484BC(&g_ftCommonDataAccesser, kind1, &f1.flag);
    fn_27_3120B8(r24 + 4, 3, &l1.args, common1);

    *(void**)r27 = lbl_108_data_1BD8;
    *(void**)(r27 + 0x4B24) = lbl_108_data_1D3C;
    *(void**)(r27 + 0x4B28) = lbl_108_data_1DC8;
    fn_108_98E4(r27 + 0x4B30, arg1);
    fn_108_98E4(r27 + 0x6AD4, arg1);
    *(void**)r27 = lbl_108_data_1590;
    r24 = r27 + 0x8A78;
    *(void**)r24 = lbl_108_data_1760;
    r22 = r24 + 4;
    *(void**)r22 = lbl_108_data_17F0;
    x = r22 + 4;
    *(void**)x = lbl_108_data_1880;
    r23 = x + 4;
    *(void**)r23 = lbl_108_data_1910;
    y = r23 + 4;
    *(void**)y = lbl_108_data_19A0;
    fn_108_9978(r23 + 0xC, arg1);
    fn_108_9978(r23 + 0x2184, arg1);
    fn_108_9978(r22 + 0x4304, arg1);
    fn_108_9978(r22 + 0x647C, arg1);
    fn_108_9978(r24 + 0x85F8, arg1);
    *(void**)r27 = lbl_108_data_10C8;
    w = r27 + 0x10000;
    *(void**)(w + 0x31E8) = lbl_108_data_12FC;
    *(void**)(w + 0x31F0) = lbl_108_data_1388;

    f2.unused = false;
    f2.flag = false;
    l2.unusedPair.a = 0;
    int kind2 = l2.unusedPair.b = 0x13;
    void* data2 = getData(arg1);
    l2.pair.a = l2.unusedPair.a;
    l2.pair.b = l2.unusedPair.b;
    l2.args.pair = &l2.pair;
    l2.args.data = data2;
    void* common2 = fn_27_14858C(&g_ftCommonDataAccesser, kind2, &f2.flag);
    fn_27_352878(w + 0x31F4, 0, &l2.args, common2);

    *(void**)r27 = lbl_108_data_EAC;
    *(char*)(r28 + 0x14F84) = 0;
    fn_27_92F10(self + 0x15004, arg1, arg0, r28, self + 0x20);
    return arg0;
}
