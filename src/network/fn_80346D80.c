#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;
extern int lbl_805A0FA8;
extern int lbl_8059F0B0;
extern int lbl_805A0F94;
extern char lbl_8059F0E0[4];
extern char lbl_8048C4C8[];
extern u64 OSGetTime(void);
extern int fn_8033891C(void);
extern int fn_803517BC(int, void *);
extern int fn_803512B4(void *);
extern int fn_80368538(void *, int, int *);
extern int fn_803683E8(void *, int, void *);
extern int fn_803363D4(char *, char *, void *, int);
extern int fn_803FC570(char *, char **, int);
extern u64 fn_803F1470(u64, u64);
extern void fn_80335638(int, const char *, ...);
extern int fn_80346B10(int, int);
#define U8(o) (*(unsigned char *)(lbl_805A0FA8 + (o)))
#define I32(o) (*(int *)(lbl_805A0FA8 + (o)))
#define PTR(o) (*(void **)(lbl_805A0FA8 + (o)))
typedef struct { int pad[66]; int value; } Entry;
int fn_80346D80(int arg0, int arg1, int arg2)
{
    char info[528];
    int data[2];
    int id;
    char str[4];
    int start;
    int pid;
    int first;
    int i;
    int result;
    int level;
    int own;
    int ok;
    int base;
    if (arg1)
        start = U8(0x1b9);
    else
        start = (U8(0x1b9) + 1) * (U8(0x1b9) < I32(0x35c) - 1);
    first = 0;
    for (;;) {
        if (!arg1 || first) {
            U8(0x1b9)++;
            if (U8(0x1b9) >= I32(0x35c))
                U8(0x1b9) = 0;
        }
        if (first && start == U8(0x1b9)) {
            u64 now;
            I32(0x1d8) = 3000;
            now = OSGetTime();
            *(u64 *)(lbl_805A0FA8 + 0x1e0) = now;
            I32(0x1cc) = 0;
            return 0;
        }
        base = lbl_805A0FA8;
        first = 1;
        pid = fn_803517BC(fn_8033891C(), (void *)(*(int *)(base + 0x314) + *(unsigned char *)(base + 0x31c + *(unsigned char *)(base + 0x1b9)) * 12));
        if (pid == 0 || pid == -1)
            continue;
        if (!fn_803512B4((void *)(I32(0x314) + U8(0x31c + U8(0x1b9)) * 12)))
            continue;
        for (i = 1; i <= U8(0xd); i++) {
            if (pid == ((Entry *)(lbl_805A0FA8 + i * 4))->value)
                break;
        }
        if (i <= U8(0xd))
            continue;
        str[0] = '0';
        result = fn_80368538(PTR(0), pid, &id);
        result |= fn_803683E8(PTR(0), id, data);
        if (result || (data[1] != 4 && data[1] != 2))
            continue;
        if (fn_803363D4(lbl_8059F0E0, str, info, 47) == -1)
            continue;
        level = fn_803FC570(str, 0, 10);
        own = (int)(u32)fn_803F1470(*(u64 *)(lbl_805A0FA8 + 0x4c0), (u64)((*(u32 *)0x800000f8 >> 2) / 1000));
        if (lbl_8059F0B0 != -1)
            own = lbl_8059F0B0;
        else {
            own = (own + 4999) / 5000;
            if (own > 10)
                own = 10;
        }
        if (!lbl_805A0F94)
            ok = 1;
        else if (!own || !level)
            ok = 0;
        else {
            int diff = own - level;
            ok = (diff < 0 ? -diff : diff) <= 1;
        }
        if (!ok) {
            fn_80335638(2, lbl_8048C4C8, pid);
            continue;
        }
        if (pid == arg2)
            arg0 = 1;
        return fn_80346B10(pid, arg0);
    }
}