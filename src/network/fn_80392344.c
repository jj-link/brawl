#pragma force_active on
typedef struct { int flag; char pad[0xa8]; int handle; } Obj;
extern int fn_803A8BA0(int, char *, unsigned int);
extern void *fn_803970CC(void *, Obj *);
extern int fn_80392238(void *, int, char *, unsigned int, int);
int fn_80392344(void *ctx, Obj *obj, int arg3, char *buf, unsigned int len, int arg6) {
    int result;
    if (obj->handle > 0) {
        result = fn_803A8BA0(obj->handle, buf, len);
    } else {
        void *entry = fn_803970CC(ctx, obj);
        if (entry != 0) {
            result = fn_80392238(entry, arg3, buf, len, arg6);
        } else {
            return -1001;
        }
    }
    if (result < 0) {
        if (obj->flag != 0) return -1002;
        if (obj->handle > 0) {
            if ((unsigned int)(result + 7) <= 1) return 0;
        } else {
            if (result == -56) return 0;
        }
        return -1001;
    }
    return result;
}