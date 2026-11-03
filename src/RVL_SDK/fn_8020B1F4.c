#pragma force_active on
extern int fn_8020CAEC(int);

typedef struct Obj {
    int field0;
    int (*cb)(int, struct Obj *);
    char pad[0x74 - 8];
    int *p74;
    int *p78;
} Obj;

void fn_8020B1F4(int arg0, Obj *arg1) {
    unsigned int aligned = ((unsigned int)arg1 + 0x53) & ~0x1F;
    if (arg0 == 0) {
        if (arg1->p74 != 0) {
            *arg1->p74 = *(int *)aligned;
        }
        if (arg1->p78 != 0) {
            *arg1->p78 = *(int *)(aligned + 4);
        }
    }
    arg1->cb(fn_8020CAEC(arg0), arg1);
}
