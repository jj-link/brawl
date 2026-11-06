#include <../../std/Include/__mem.h>
extern int strncmp(const char *, const char *, unsigned long);
#pragma force_active on

extern int CanReceiveOnSocket(int);
extern int recv(int, void *, unsigned long, int);
extern int closesocket(int);
extern void fn_8035E00C(void *);
extern int fn_8035A590(int);
extern void *fn_8035A598(int, int);
extern int fn_80388590(void *);
extern void *fn_8035B1C4(int, int *);
extern void fn_8035B120(int, int *);
extern void fn_8035A4FC(int);
extern void fn_8038795C(void *, void *, int);
extern int fn_8038B83C(void *);
extern int fn_8038C87C(void *);
extern char *lbl_8059FBCC;
extern int lbl_805A1128;

#define FIELD(type, off) (*(type *)((char *)self + (off)))
typedef void (*Callback)(void *, int, int, int);

int fn_8038CCCC(void *self) {
    int locals[3];
    int i;
    int *ptr;
    void *temp;
    int temp2;
    int oldlen;
    int len;
    int received;
    const char *prefix;
    char *buffer;
    const char *cmpPrefix;
    int result;

    if (CanReceiveOnSocket(FIELD(int, 0x6B4)) == 0) return 0;
    oldlen = FIELD(int, 0x80);
    received = recv(FIELD(int, 0x6B4), FIELD(char *, 0x7C) + oldlen, 0x1000 - oldlen, 0);
    if ((unsigned int)(received + 1) <= 1U) {
        len = FIELD(int, 0x80);
        if (len > 0) {
            prefix = lbl_8059FBCC;
            if ((unsigned int)len > strlen(prefix)) {
                cmpPrefix = lbl_8059FBCC;
                buffer = FIELD(char *, 0x7C);
                if (strncmp(buffer, cmpPrefix, strlen(cmpPrefix)) == 0) {
                    FIELD(char *, 0x6B0) = buffer + strlen(prefix);
                    FIELD(Callback, 0x488)(self, 5, lbl_805A1128, FIELD(int, 0x494));
                }
            }
        }
        FIELD(Callback, 0x488)(self, 4, lbl_805A1128, FIELD(int, 0x494));
        if (FIELD(int, 0x7C) != 0) {
            fn_8035E00C(FIELD(void *, 0x7C));
        }
        FIELD(int, 0x7C) = 0;
        FIELD(int, 0x80) = 0;
        if (FIELD(int, 0x6B4) != -1) {
            closesocket(FIELD(int, 0x6B4));
        }
        FIELD(int, 0x6B4) = -1;
        FIELD(int, 0x0) = 1;
        if (FIELD(int, 0x8) != 0) {
            i = 0;
            while (i < fn_8035A590(FIELD(int, 0x8))) {
                locals[2] = *(int *)fn_8035A598(FIELD(int, 0x8), i);
                temp = fn_8035B1C4(fn_80388590(self), &locals[2]);
                if (temp != 0) {
                    temp2 = *(int *)((char *)temp + 4) - 1;
                    *(int *)((char *)temp + 4) = temp2;
                    if (temp2 == 0) {
                        fn_8035B120(fn_80388590(self), &locals[2]);
                    }
                }
                i++;
            }
            fn_8035A4FC(FIELD(int, 0x8));
            FIELD(int, 0x8) = 0;
        }
        ptr = (int *)self;
        FIELD(int, 0x484) = -1;
        i = 0;
        while (i < FIELD(int, 0x480)) {
            locals[0] = ptr[0x21];
            temp = fn_8035B1C4(fn_80388590(self), &locals[0]);
            if (temp != 0) {
                temp2 = *(int *)((char *)temp + 4) - 1;
                *(int *)((char *)temp + 4) = temp2;
                if (temp2 == 0) {
                    fn_8035B120(fn_80388590(self), &locals[0]);
                }
            }
            ptr++;
            i++;
        }
        FIELD(int, 0x480) = 0;
        return 3;
    }
    result = 0;
    FIELD(int, 0x80) += received;
    if (FIELD(int, 0x0) == 2 || FIELD(int, 0x7CC) > 0) {
        fn_8038795C((char *)self + 0x6C0, FIELD(char *, 0x7C) + oldlen, FIELD(int, 0x80) - oldlen);
    }
    if (FIELD(int, 0x0) == 3) {
        result = fn_8038B83C(self);
    }
    if (result != 0) return result;
    if (FIELD(int, 0x0) == 2 && FIELD(int, 0x80) > 0) {
        return fn_8038C87C(self);
    }
    return 0;
}
