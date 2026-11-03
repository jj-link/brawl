#pragma force_active on
extern void fn_8022F500(void *, int);
extern void *fn_8022F77C(void *);
extern void fn_8024ABC4(unsigned short, void *);
typedef struct { char a[0x18]; char queue[0x50]; unsigned short id; char b[9]; unsigned char flag; } Obj;
void fn_80256858(Obj *arg0, int arg1) {
    void *p;
    if (arg1 != 0) {
        fn_8022F500(arg0->queue, arg1);
    }
    while (arg0->flag == 0) {
        p = fn_8022F77C(arg0->queue);
        if (p == 0) break;
        fn_8024ABC4(arg0->id, p);
    }
}