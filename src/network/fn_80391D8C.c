#pragma force_active on

typedef struct {
    char pad[0x14];
    void *field14;
    char pad2[0xC];
    void *field24;
} NetObj;

extern void fn_803900A0(void *);
extern void *fn_80390044(int, int);
extern void fn_80391000(void *, void *, int, int);
extern int fn_80391C58(void *, int, int *);
extern int fn_80392734(const char *, const char *);
extern char lbl_80491658[];

int fn_80391D8C(NetObj *obj, int arg1, void **out) {
    int sp8;
    int result;
    void *ptr;

    if (obj->field14 == 0) return -1;
    if (obj->field24 != 0) {
        fn_803900A0(obj->field24);
        obj->field24 = 0;
    }
    result = fn_80391C58(obj, arg1, &sp8);
    if (result >= 0) {
        ptr = fn_80390044(result + 1, 4);
        obj->field24 = ptr;
        if (ptr == 0) return -1;
        ((char *)ptr)[result] = 0;
        fn_80391000(obj, obj->field24, sp8, result);
        *out = obj->field24;
        return result;
    }
    if (fn_80392734(lbl_80491658, (const char *)arg1) == 0) {
        ptr = fn_80390044(4, 4);
        obj->field24 = ptr;
        if (ptr == 0) return -1;
        ((char *)ptr)[3] = 0;
        fn_80391000(obj, obj->field24, 9, 3);
        *out = obj->field24;
        return 3;
    }
    return -1;
}