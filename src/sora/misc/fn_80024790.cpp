#pragma force_active on
typedef int s32;
typedef unsigned char u8;

struct Entry {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
};

extern "C" {
void fn_80024824(s32);
int fn_801D7144(void);
int fn_801D712C(void);
int fn_801D714C(void);
int fn_801D7134(void);
extern s32 g_HeapInfos[];

void fn_80024790(Entry* arg0) {
    Entry* p = arg0;
    for (;;) {
        if (p->w0 == 0) {
            break;
        }
        p++;
    }
    do {
        s32 idx = *(s32*)((u8*)p - 12);
        p--;
        if (*(s32*)((u8*)g_HeapInfos + (idx << 4) + 8) != 0) {
            fn_80024824(p->w1);
        }
    } while (p != arg0);
    fn_801D7144();
    fn_801D712C();
    fn_801D714C();
    fn_801D7134();
}
}
