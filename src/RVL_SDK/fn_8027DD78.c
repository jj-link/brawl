#pragma force_active on
typedef struct {
    void *arr;
    char pad[4];
    int val;
} fn_8027DD78_Obj;

int fn_8027DD78(fn_8027DD78_Obj *obj, int index) {
    return ((int *)obj->arr)[index + obj->val * 2 + 2];
}
