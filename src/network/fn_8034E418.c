#pragma force_active on
typedef void (*SendCallback)(int, int);

typedef struct {
    unsigned char pad000[0x900];
    SendCallback callback;
    unsigned char pad904[0xC];
    unsigned short maxLength;
} Transport;

extern int fn_80335238(void);
extern int fn_8033A94C(int);
extern void fn_80335638(int, const char *, ...);
extern void *fn_8033ABE8(int);
extern int fn_80374AC4(void *, const void *, int, int);
extern char lbl_8048CF70[];
extern char lbl_8048CF8C[];
extern Transport *lbl_805A0FB0;

int DWC_SendUnreliable(int aid, const void *data, int length)
{
    SendCallback callback;

    if (fn_80335238() != 0) {
        return 0;
    }

    if (fn_8033A94C(aid) == 0) {
        fn_80335638(8, lbl_8048CF70, aid);
        return 0;
    }

    if (length > lbl_805A0FB0->maxLength) {
        fn_80335638(0x8000, lbl_8048CF8C, length,
                     lbl_805A0FB0->maxLength);
        return 0;
    }

    fn_80374AC4(fn_8033ABE8(aid), data, length, 0);

    callback = lbl_805A0FB0->callback;
    if (callback != 0) {
        callback(length, aid);
    }

    return 1;
}
