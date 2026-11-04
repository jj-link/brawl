#include <string.h>
#pragma force_active on

typedef unsigned char u8;
typedef void (*Callback)(int, int, int, int, int, int);
typedef struct State {
    char pad0[0x1C];
    char connection[8];
    int state;
    int previous;
    char pad2C[0x88 - 0x2C];
    Callback callback;
    int context;
    char pad90[0x376 - 0x90];
    u8 status;
    char pad377[0x805 - 0x377];
    u8 flag;
} State;

extern State *lbl_805A0F88;
extern char lbl_80489E48[];
extern char lbl_80533730[];
extern char lbl_805337B0[];
extern char lbl_8059F088[4];
extern char lbl_8059F08C[4];
extern char lbl_8059F090[4];

extern void fn_80335638(int, const char *, ...);
extern int fn_80335238(void);
extern void fn_8033524C(int, int);
extern int fn_803371DC(int);
extern int fn_803685D0(void *, int);
extern int fn_80368538(void *, int, int *);
extern int fn_803683E8(void *, int, void *);
extern int fn_803363D4(const char *, char *, const char *, char);
extern int fn_803FC570(char *, char **, int);
extern int fn_80342554(void);
extern int fn_8033FE10(int, int);
extern void fn_80342328(int);
extern void fn_8033B208(void);
extern void fn_8033D7D4(int, void (*)(void), int, int, int, int, void *, int);

int fn_8033A200(int arg0, Callback arg1, int arg2, int arg3, int arg4, int arg5, void *arg6, int arg7)
{
    const char *base = lbl_80489E48;
    char info[528];
    int data[2];
    int id = -1;
    char str[4];
    int result;
    int error;
    u8 first;
    u8 second;
    int value;

    fn_80335638(4, base + 0x320);
    if (fn_80335238() != 0 || lbl_805A0F88->state != 3) {
        fn_80335638(4, base + 0xC8);
        return 0;
    }
    memset(lbl_80533730, 0, 0x80);
    memset(lbl_805337B0, 0, 0x100);
    lbl_805A0F88->callback = arg1;
    lbl_805A0F88->context = arg2;
    lbl_805A0F88->previous = lbl_805A0F88->state;
    lbl_805A0F88->state = 5;
    result = fn_803371DC(arg0);
    if (result == 0 || fn_803685D0(lbl_805A0F88->connection, result) == 0) {
        fn_80335638(2, base + 0x350, result);
        error = 0xB;
        goto error;
    }
    fn_80368538(lbl_805A0F88->connection, result, &id);
    fn_803683E8(lbl_805A0F88->connection, id, data);
    if (data[1] != 6) {
        fn_80335638(2, base + 0x368, result);
        error = 0xB;
        goto error;
    }
    str[0] = '0';
    fn_803363D4(lbl_8059F088, str, info, 0x2F);
    first = fn_803FC570(str, 0, 10);
    fn_803363D4(lbl_8059F08C, str, info, 0x2F);
    second = fn_803FC570(str, 0, 10);
    if (second == first) {
        fn_80335638(2, base + 0x384, result);
        error = 0xD;
        goto error;
    }
    fn_803363D4(lbl_8059F090, str, info, 0x2F);
    value = fn_803FC570(str, 0, 10);
    if (fn_8033FE10(fn_80342554(), value) == 0) {
        fn_80335638(2, base + 0x3A0, result);
        error = 0x12;
        goto error;
    }
    lbl_805A0F88->status = 3;
    lbl_805A0F88->flag = 0;
    fn_8033D7D4(result, fn_8033B208, 0, arg3, arg4, arg5, arg6, arg7);
    return 1;

error:
    fn_8033524C(error, 0);
    lbl_805A0F88->callback(error, 0, 1, 0, 0, lbl_805A0F88->context);
    if (lbl_805A0F88 != 0) {
        int state = lbl_805A0F88->state;
        if (state == 5) {
            lbl_805A0F88->previous = state;
            lbl_805A0F88->state = 3;
            fn_80342328(1);
        }
    }
    return 1;
}
