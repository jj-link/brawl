#include <stdio.h>
#include <string.h>
#pragma force_active on

extern int lbl_805A1058;
extern char lbl_8048FBE0[];
extern unsigned int lbl_80535A80[];
extern char lbl_8059F9AC;
extern char lbl_8059F9C4;
extern char lbl_8059F9CC;
extern char lbl_8059F9D0;

extern char *SOInetNtoA(unsigned int *);
extern int fn_8035D728(void);
extern void fn_80379A3C(void *, char *, int, int, int);
extern int sendto(int, const void *, int, int, const void *, int);

typedef struct {
    char data[0x578];
    int len;
} Msg;

#define APPEND_STR(s)                         \
    {                                         \
        int n = strlen(s) + 1;                \
        if (n > 0x578 - msg.len) {            \
            n = 0x578 - msg.len;              \
        }                                     \
        if (n > 0) {                          \
            memcpy(&msg.data[msg.len], s, n); \
            msg.len += n;                     \
            msg.data[msg.len - 1] = 0;        \
        }                                     \
    }

void fn_8037AC14(char *self, int arg1)
{
    int n;
    char *base;
    unsigned int sp8;
    char sp5C[20];
    char sp48[20];
    char sp34[20];
    char sp20[20];
    char spC[20];
    Msg msg;
    Msg sp70;
    unsigned int *p;
    int i;
    char *ip;
    char *str;
    int tmp;

    base = lbl_8048FBE0;
    msg.len = 0;
    msg.data[0] = 3;
    memcpy(msg.data + 1, self + 0x84, 4);
    msg.len = 5;
    p = lbl_80535A80;

    for (i = 0; i < lbl_805A1058; p++, i++) {
        sprintf(sp5C, base + 0x4E0, i);
        APPEND_STR(sp5C)
        sp8 = *p;
        ip = SOInetNtoA(&sp8);
        APPEND_STR(ip)
    }

    {
        char *key = base + 0x4EC;
        APPEND_STR(key)
    }
    sprintf(sp48, &lbl_8059F9AC, *(int *)(self + 0xC0));
    APPEND_STR(sp48)
    {
        char *key = (char *)(unsigned long)&lbl_8059F9C4;
        APPEND_STR(key)
    }
    str = &lbl_8059F9D0;
    if (*(int *)(self + 0xC8) != 0) {
        str = &lbl_8059F9CC;
    }
    APPEND_STR(str)
    if (arg1 != 0) {
        {
            char *key = base + 0x4F8;
            APPEND_STR(key)
        }
        sprintf(sp34, &lbl_8059F9AC, arg1);
        APPEND_STR(sp34)
    }
    {
        char *key = base + 0x508;
        APPEND_STR(key)
    }
    APPEND_STR(self + 4)
    if (*(int *)(self + 0xA8) != 0) {
        {
            char *key = base + 0x514;
            APPEND_STR(key)
        }
        sprintf(sp20, &lbl_8059F9AC, *(int *)(self + 0x104));
        APPEND_STR(sp20)
        {
            char *key = base + 0x520;
            APPEND_STR(key)
        }
        sprintf(spC, &lbl_8059F9AC, *(unsigned short *)(self + 0x108));
        APPEND_STR(spC)
    }

    if (arg1 != 2) {
        memcpy(sp70.data, msg.data, msg.len);
        sp70.len = msg.len;
        fn_80379A3C(self, sp70.data, 0, 0xFF, 0);
        fn_80379A3C(self, sp70.data, 1, 0xFF, 0);
        fn_80379A3C(self, sp70.data, 2, 0xFF, 0);
        if (0x578 - sp70.len < 1) {
            sp70.len = msg.len;
            fn_80379A3C(self, sp70.data, 0, 0xFF, 0);
            fn_80379A3C(self, sp70.data, 1, 0, 0);
            fn_80379A3C(self, sp70.data, 2, 0, 0);
        }
        memcpy(msg.data, sp70.data, sp70.len);
        msg.len = sp70.len;
    } else if (0x578 - msg.len >= 1) {
        int len = msg.len;
        msg.data[len] = 0;
        msg.len = len + 1;
    }

    sendto(*(int *)self, msg.data, msg.len, 0, self + 0xCC, 8);
    tmp = fn_8035D728();
    *(int *)(self + 0xAC) = tmp;
    *(int *)(self + 0xB0) = tmp;
    if (arg1 != 0) {
        *(int *)(self + 0xB4) = 0;
    }
}
