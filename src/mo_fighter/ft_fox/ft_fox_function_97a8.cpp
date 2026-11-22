#pragma force_active on

extern "C" {
extern unsigned char g_ftCommonDataAccesser;
extern unsigned char lbl_97_data_B24[];
extern unsigned char lbl_97_data_1F30[];
extern unsigned char lbl_97_data_1FDC[];
extern unsigned char lbl_97_data_2068[];
extern unsigned char lbl_97_data_1B88[];
extern unsigned char lbl_97_data_1CE8[];
extern unsigned char lbl_97_data_1D70[];
extern unsigned char lbl_97_data_1564[];
extern unsigned char lbl_97_data_172C[];
extern unsigned char lbl_97_data_17B8[];
extern unsigned char lbl_97_data_1844[];
extern unsigned char lbl_97_data_18D0[];
extern unsigned char lbl_97_data_195C[];
extern unsigned char lbl_97_data_10B0[];
extern unsigned char lbl_97_data_12DC[];
extern unsigned char lbl_97_data_1364[];
extern unsigned char lbl_97_data_E9C[];

void fn_27_1A558C(void* self, int flag);
void fn_27_19F434(void* array, int count, int size);
int fn_27_1484BC(void* accesser, int kind, bool* flag);
void fn_27_3120B8(void* self, int kind, void* args, int common);
int fn_27_148380(void* accesser, int kind, bool* flag);
void fn_27_31EEEC(void* self, int kind, void* args, int common);
void fn_27_92F10(void* a, void* accesser, void* self, void* b, void* c);
void* fn_97_9A14(void* self, void* fighter);
void* fn_97_9AA8(void* self, void* fighter);
}

struct Pair { int a, b; };
struct Args { Pair* pair; void* data; };
struct Flags { bool unused; bool flag; };
struct PairsArgs { Pair unusedPair; Pair pair; Args args; };

inline void* getData(void* fighter) {
    return *(void**)(*(char**)((char*)fighter + 0xd8) + 0xc0);
}

extern "C" void* fn_97_97A8(void* arg0, void* arg1) {
    unsigned char* self = (unsigned char*)arg0;
    fn_27_1A558C(arg0, 0);
    fn_27_19F434(self + 0x20, 5, 0);
    unsigned char* r28 = self + 0x7C;
    *(void**)(self + 0x7C) = lbl_97_data_B24;
    *(void**)(self + 0x80) = lbl_97_data_B24 + 0x10;
    unsigned char* r27 = r28 + 8;
    *(void**)(self + 0x84) = lbl_97_data_1F30;
    unsigned char* sub = r27 + 4;
    *(void**)sub = lbl_97_data_1FDC;
    unsigned char* r24 = sub + 8;
    *(void**)(self + 0x90) = lbl_97_data_2068;

    {
        Flags f;
        f.unused = false;
        f.flag = false;
        PairsArgs b;
        b.unusedPair.a = 0;
        int kind = b.unusedPair.b = 6;
        void* data = getData(arg1);
        b.pair.a = b.unusedPair.a;
        b.pair.b = b.unusedPair.b;
        b.args.pair = &b.pair;
        b.args.data = data;
        int common = fn_27_1484BC(&g_ftCommonDataAccesser, kind, &f.flag);
        fn_27_3120B8(r24 + 4, 3, &b.args, common);
    }

    *(void**)(r27 + 0) = lbl_97_data_1B88;
    *(void**)(r27 + 0x4B24) = lbl_97_data_1CE8;
    *(void**)(r27 + 0x4B28) = lbl_97_data_1D70;
    fn_97_9A14(r27 + 0x4B30, arg1);
    fn_97_9A14(r27 + 0x6918, arg1);
    *(void**)(r27 + 0) = lbl_97_data_1564;
    r24 = r27 + 0x8700;
    *(void**)r24 = lbl_97_data_172C;
    unsigned char* r23;
    unsigned char* r22 = r24 + 4;
    *(void**)r22 = lbl_97_data_17B8;
    unsigned char* x = r22 + 4;
    *(void**)x = lbl_97_data_1844;
    r23 = x + 4;
    *(void**)r23 = lbl_97_data_18D0;
    unsigned char* y = r23 + 4;
    *(void**)y = lbl_97_data_195C;
    fn_97_9AA8(r23 + 0xC, arg1);
    fn_97_9AA8(r23 + 0x2188, arg1);
    fn_97_9AA8(r22 + 0x430C, arg1);
    fn_97_9AA8(r22 + 0x6488, arg1);
    fn_97_9AA8(r24 + 0x10000 - 0x79F8, arg1);
    *(void**)(r27 + 0) = lbl_97_data_10B0;
    unsigned char* w = r27 + 0x10000;
    *(void**)(w + 0x2E84) = lbl_97_data_12DC;
    *(void**)(w + 0x2E8C) = lbl_97_data_1364;

    {
        Flags f;
        f.unused = false;
        f.flag = false;
        PairsArgs b;
        b.unusedPair.a = 0;
        int kind = b.unusedPair.b = 6;
        void* data = getData(arg1);
        b.pair.a = b.unusedPair.a;
        b.pair.b = b.unusedPair.b;
        b.args.pair = &b.pair;
        b.args.data = data;
        int common = fn_27_148380(&g_ftCommonDataAccesser, kind, &f.flag);
        fn_27_31EEEC(w + 0x2E90, 0, &b.args, common);
    }

    *(void**)(r27 + 0) = lbl_97_data_E9C;
    *(unsigned char*)(r28 + 0x14C14) = 0;
    fn_27_92F10(self + 0x14C94, arg1, arg0, r28, self + 0x20);
    return arg0;
}
