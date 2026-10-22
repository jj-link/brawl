#pragma force_active on
extern int fn_80372FC0(void *, int, int *);
extern void fn_8036AAF0(void *, int, int);
extern void fn_80373290(void *, int, const char *);
extern char lbl_8048F184[];

struct Obj {
    char pad[0x1f0];
    int field1f0;
    int field1f4;
};

int fn_8036C218(void **arg0) {
    int sp8;
    int ret;
    struct Obj *obj;

    obj = (struct Obj *)*arg0;
    ret = fn_80372FC0(arg0, obj->field1f0, &sp8);
    if (ret != 0) {
        return ret;
    }
    if (sp8 == 4) {
        fn_80373290(arg0, 0x107, lbl_8048F184);
        fn_8036AAF0(arg0, 4, 1);
        return 4;
    }
    if (sp8 == 0) {
        return 0;
    }
    obj->field1f4 = 2;
    return 0;
}
