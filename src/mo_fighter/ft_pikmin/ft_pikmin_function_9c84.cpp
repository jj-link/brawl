#pragma force_active on
extern char lbl_113_data_2340[];

typedef struct Fn113Obj {
    void *vtbl;      /* 0x00 */
    char pad_04[0x0C];
    int field_10;    /* 0x10 */
    int field_14;    /* 0x14 */
    int field_18;    /* 0x18 */
} Fn113Obj;

extern "C" void fn_113_9C84(Fn113Obj *obj, int a, int b, int c)
{
    obj->vtbl = lbl_113_data_2340;
    obj->field_10 = a;
    obj->field_14 = b;
    obj->field_18 = c;
}
