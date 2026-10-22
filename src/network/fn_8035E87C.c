#pragma force_active on
typedef struct {
    int intArray[4];
    int lock[6];
    int data[40];
} Pool;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void *unk20;
    void (*unk24)(void *);
} Obj;

extern Pool lbl_805348E0;
extern unsigned int fn_8035D728(void);
extern void fn_8035D24C(void *);
extern void fn_8035D250(void *, void *);

void fn_8035E87C(Obj *arg0, int arg1) {
    Pool *pool;
    int found;
    int i;
    int *slot;
    
    pool = &lbl_805348E0;
    found = -1;
    arg0->unk1C = 1;
    arg0->unk10 = 1;
    arg0->unk14 = 1;
    arg0->unk4 = arg1;
    arg0->unk8 = fn_8035D728();
    if (arg0->unk24 != 0) {
        arg0->unk24(arg0->unk20);
    }
    fn_8035D24C(pool->lock);
    for (i = 0; i < 40; i++) {
        if (pool->data[i] == 0) {
            found = i;
            break;
        }
    }
    slot = &pool->intArray[found];
    slot[10] = (int)arg0;
    fn_8035D250(pool->lock, slot);
}
