#include <types.h>
#pragma force_active on
extern "C" {
void fn_27_1A558C(void*, int);
void fn_27_19F434(void*, int, int);
void* fn_27_1484BC(void*, int, void*);
void* fn_27_1486C8(void*, int, void*);
void fn_27_3120B8(void*, int, void*, void*);
void fn_27_3C8440(void*, int, void*, void*);
void fn_27_92F10(void*, void*, void*, void*, void*);
void fn_125_993C(void*, void*);
void fn_125_99D0(void*, void*);
extern unsigned char g_ftCommonDataAccesser;
extern char lbl_125_data_10BC[];
extern char lbl_125_data_12EC[];
extern char lbl_125_data_1374[];
extern char lbl_125_data_157C[];
extern char lbl_125_data_1748[];
extern char lbl_125_data_17D8[];
extern char lbl_125_data_1868[];
extern char lbl_125_data_18F8[];
extern char lbl_125_data_1988[];
extern char lbl_125_data_1BB8[];
extern char lbl_125_data_1D1C[];
extern char lbl_125_data_1DA8[];
extern char lbl_125_data_1F6C[];
extern char lbl_125_data_2018[];
extern char lbl_125_data_20A4[];
extern char lbl_125_data_B24[];
extern char lbl_125_data_EA4[];
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

extern "C" void* fn_125_96D0(void* arg0, void* arg1) {
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
    *(void**)r28 = lbl_125_data_B24;
    *(void**)(r28 + 4) = lbl_125_data_B24 + 0x10;
    r27 = r28 + 8;
    *(void**)r27 = lbl_125_data_1F6C;
    sub = r27 + 4;
    *(void**)sub = lbl_125_data_2018;
    r24 = sub + 8;
    *(void**)r24 = lbl_125_data_20A4;

    f1.unused = false;
    f1.flag = false;
    l1.unusedPair.a = 0;
    int kind1 = l1.unusedPair.b = 0x2c;
    void* data1 = getData(arg1);
    l1.pair.a = l1.unusedPair.a;
    l1.pair.b = l1.unusedPair.b;
    l1.args.pair = &l1.pair;
    l1.args.data = data1;
    void* common1 = fn_27_1484BC(&g_ftCommonDataAccesser, kind1, &f1.flag);
    fn_27_3120B8(r24 + 4, 3, &l1.args, common1);

    *(void**)r27 = lbl_125_data_1BB8;
    *(void**)(r27 + 0x4B24) = lbl_125_data_1D1C;
    *(void**)(r27 + 0x4B28) = lbl_125_data_1DA8;
    fn_125_993C(r27 + 0x4B30, arg1);
    fn_125_993C(r27 + 0x6918, arg1);
    *(void**)r27 = lbl_125_data_157C;
    r24 = r27 + 0x8700;
    *(void**)r24 = lbl_125_data_1748;
    r22 = r24 + 4;
    *(void**)r22 = lbl_125_data_17D8;
    x = r22 + 4;
    *(void**)x = lbl_125_data_1868;
    r23 = x + 4;
    *(void**)r23 = lbl_125_data_18F8;
    y = r23 + 4;
    *(void**)y = lbl_125_data_1988;
    fn_125_99D0(r23 + 0xC, arg1);
    fn_125_99D0(r23 + 0x2188, arg1);
    fn_125_99D0(r22 + 0x430C, arg1);
    fn_125_99D0(r22 + 0x6488, arg1);
    fn_125_99D0(r24 + 0x8608, arg1);
    *(void**)r27 = lbl_125_data_10BC;
    w = r27 + 0x12E84;
    *(void**)w = lbl_125_data_12EC;
    *(void**)(w + 8) = lbl_125_data_1374;

    f2.unused = false;
    f2.flag = false;
    l2.unusedPair.a = 0;
    int kind2 = l2.unusedPair.b = 0x2c;
    void* data2 = getData(arg1);
    l2.pair.a = l2.unusedPair.a;
    l2.pair.b = l2.unusedPair.b;
    l2.args.pair = &l2.pair;
    l2.args.data = data2;
    void* common2 = fn_27_1486C8(&g_ftCommonDataAccesser, kind2, &f2.flag);
    fn_27_3C8440(w + 0xC, 0, &l2.args, common2);

    *(void**)r27 = lbl_125_data_EA4;
    *(char*)(r28 + 0x14C20) = 0;
    fn_27_92F10(self + 0x14CA0, arg1, arg0, r28, self + 0x20);
    return arg0;
}
