#pragma force_active on
typedef int s32;

typedef s32 (*Callback1)(s32, s32 *, s32 *, s32, s32);
typedef s32 (*Callback2)(s32 *, s32 *, s32, void *, void *, s32);
typedef s32 (*Callback3)(s32, void *, s32);

s32 fn_803974FC(void);
s32 fn_80397580(s32);
void *fn_803970DC(s32, s32);
s32 fn_80396188(void *);
void *fn_8039705C(s32, void *);
void *fn_80397094(s32, void *);
s32 fn_80397598(void *);
s32 fn_803961FC(void *);
void fn_80390044(void);
void fn_803900A0(void);

s32 fn_8039632C(s32 arg0, s32 arg1, s32 *arg2) {
    s32 context;
    s32 temp2;
    void *temp;
    s32 callbackResult;
    Callback2 callback2;
    s32 value;
    s32 sp8;
    s32 result;
    Callback3 callback3;
    void *object;

    context = fn_80397580(fn_803974FC());
    object = fn_803970DC(context, arg0);
    result = 0;

    switch (arg1) {
    case 1:
        if (object != 0 &&
            (temp = fn_8039705C(context, object)) != 0 &&
            (arg1 = *(s32 *)((char *)temp + 0x250)) != 0) {
            callbackResult = ((Callback1)arg1)(arg2[0], arg2 + 1, arg2 + 2, arg2[3], fn_80396188(object));
        } else {
            callbackResult = -1;
        }
        result = callbackResult;
        break;

    case 2:
        if (object != 0) {
            temp = fn_80397094(context, object);
            if (temp != 0) {
                callback2 = *(Callback2 *)((char *)temp + 0x2C);
                if (callback2 != 0) {
                    sp8 = arg2[0];
                    value = fn_80397598(object);
                    temp2 = fn_80396188(object);
                    result = callback2(&sp8, arg2 + 1, value, (void *)fn_80390044, (void *)fn_803900A0, temp2);
                    arg2[0] = result;
                    if (result != 0 && sp8 != 0) {
                        arg2[2] = 0;
                    }
                }
            }
        }
        result = 0;
        break;

    case 3:
        break;

    case 4:
        if (object != 0) {
            callback3 = *(Callback3 *)((char *)object + 0x30);
            if (callback3 != 0) {
                temp = fn_80397094(context, object);
                if (temp != 0) {
                    value = fn_803961FC(object);
                    temp2 = fn_80396188(object);
                    callback3(value, temp, temp2);
                }
            }
        }
        result = 0;
        break;
    }

    return result;
}
