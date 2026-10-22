#pragma force_active on
extern int fn_8020CAEC(int);

typedef struct Obj {
    int unk0;
    int (*cb)(int, struct Obj *);
    char *sub;
    char pad[0xAC];
    int unkB8;
} Obj;

void fn_8020C2B4(int arg0, Obj *obj) {
    if (arg0 >= 0) {
        *(int *)obj->sub = arg0;
        obj->sub[0x89] = 2;
        if (obj->unkB8 == 0) {
            obj->sub[0x8A] = 3;
        } else {
            obj->sub[0x8A] = 5;
        }
        obj->cb(0, obj);
        return;
    }
    obj->cb(fn_8020CAEC(arg0), obj);
}
