#pragma force_active on
typedef struct Obj { int idx; char pad04[0x18]; unsigned char flag; char pad1d[7]; char *base; char pad28[0x1c]; unsigned char enabled; } Obj;
extern int fn_8027B4A8(char *, int);
extern void fn_8021A558(int, int);
void fn_8027ABA8(Obj *obj) {
    if (obj->idx < 4 && fn_8027B4A8(obj->base, obj->idx) == 0 && obj->enabled) {
        obj->flag = 1;
        fn_8021A558(obj->idx, 1);
    }
}