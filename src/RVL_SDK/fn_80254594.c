#pragma force_active on

extern void *fn_80251AD0(void);
extern void fn_80250A6C(void *, int, int, int);
extern void fn_802533C8(void *, int, int);

typedef struct { unsigned char pad[0x6C]; unsigned char unk6C; } Obj;

void fn_80254594(Obj *arg0, int arg1) {
    void *entry = fn_80251AD0();
    if (arg0->unk6C != 5) {
        fn_80250A6C(arg0, arg1, 0, 1);
    } else {
        fn_802533C8(entry, 9, 0);
    }
}
