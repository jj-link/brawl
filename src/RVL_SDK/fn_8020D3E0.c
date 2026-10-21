#pragma force_active on
extern int fn_8020CAEC(int);

typedef struct {
    int field0;
    int (*cb)(int, void *);
} Obj;

int fn_8020D3E0(int a, Obj *obj) {
    int result = fn_8020CAEC(a);
    return obj->cb(result, obj);
}
