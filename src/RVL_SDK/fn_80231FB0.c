#pragma force_active on
typedef struct Obj { char pad[12]; int value; char pad2[4]; short field; } Obj;
extern char lbl_805297D0[];
extern void fn_802301F0(void *, Obj *);
extern void fn_80230104(void *, Obj *);
void fn_80231FB0(Obj *obj, short arg1, int arg2) {
    fn_802301F0(lbl_805297D0 + 0x40, obj);
    obj->field = arg1;
    obj->value = arg2;
    fn_80230104(lbl_805297D0 + 0x40, obj);
}