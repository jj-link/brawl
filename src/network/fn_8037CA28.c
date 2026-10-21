#pragma force_active on
typedef int s32;
typedef void (*Callback)(void);

typedef struct Object {
    char pad0[0x14];
    char *name;
    char pad18[0x178];
    s32 field190;
    s32 field194;
    s32 field198;
    s32 field19C;
    Callback field1A0;
    Callback field1A4;
    Callback field1A8;
    Callback field1AC;
} Object;

extern Object *fn_8037C720(s32);
extern int strncmp(const char *, const char *, unsigned long);
extern char lbl_804905F8[];
extern void fn_8037D0D8(void);
extern void fn_8037D2AC(void);
extern void fn_8037D304(void);
extern void fn_8037D520(void);

s32 fn_8037CA28(s32 arg0, s32 arg1)
{
    Object *obj = fn_8037C720(arg0);

    if (obj == 0)
        return 0;

    if (obj->field194 == arg1)
        return 1;

    if (obj->field190 != 0 && obj->field194 != arg1)
        return 0;

    if (arg1 == 0 && strncmp(obj->name, lbl_804905F8, 8) == 0)
        return 0;

    obj->field194 = arg1;

    if (arg1 == 0) {
        obj->field190 = 0;
        return 1;
    }

    obj->field190 = 0;
    obj->field1A0 = fn_8037D0D8;
    obj->field1A4 = fn_8037D2AC;
    obj->field1A8 = fn_8037D304;
    obj->field1AC = fn_8037D520;
    obj->field198 = 0;
    obj->field19C = 0;
    return 1;
}
