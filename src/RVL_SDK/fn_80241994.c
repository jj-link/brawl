#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern u8 lbl_80529CF8[];
extern u8 lbl_804814C8[];
extern void *fn_8023A0F0(u8 *);
extern void *fn_80239F18(u8 *);
extern void fn_80245158(u8 *);
extern void fn_80244F74(u8 *, s32, u8 *);
extern void fn_80231A74(s32, void *, s32, s32, s32, s32, s32, s32);
extern s32 fn_803F6150(const void *, const void *, u32);
extern void *memcpy(void *, const void *, u32);
extern void fn_802319E4(s32, void *);
extern void fn_802319FC(s32, void *, s32);
extern void fn_80231A2C(s32, void *, s32, void *, void *);
extern void fn_80231FB0(void *, s32, s32);
extern void fn_802464CC(u8);
extern void fn_80241920(void);

void fn_80241994(u8 *arg0)
{
    u8 *base2 = lbl_804814C8;
    s32 var_r30;
    u8 *base = lbl_80529CF8;
    s32 var_r28;
    u8 *obj;
    u8 *ep;
    s32 i;

    var_r28 = 0;
    var_r30 = 0;

    if (base[0x27C0] >= 4) {
        fn_80231A74(0xD0003, base2 + 0x7BC, arg0[0], arg0[1], arg0[2], arg0[3], arg0[4], arg0[5]);
    }
    if (base[0x1979] == 0 && base[0x20] == 1) {
        if (fn_8023A0F0(arg0) == 0) {
            ep = lbl_80529CF8 + 0x1F30;
            for (i = 0; i < 2; i++) {
                if (!(ep[0x76] & 0x80)) break;
                var_r30++;
                if (!(ep[0xFE] & 0x80)) break;
                var_r30++;
                if (!(ep[0x186] & 0x80)) break;
                var_r30++;
                if (!(ep[0x20E] & 0x80)) break;
                var_r30++;
                if (!(ep[0x296] & 0x80)) break;
                var_r30++;
                if (!(ep[0x31E] & 0x80)) break;
                var_r30++;
                if (!(ep[0x3A6] & 0x80)) break;
                var_r30++;
                if (!(ep[0x42E] & 0x80)) break;
                var_r30++;
                ep += 0x440;
            }
        }
        if (var_r30 >= 0x10) {
            fn_80245158(arg0);
            return;
        }
        fn_80244F74(arg0, base[0x21], base + 0x22);
        return;
    }

    obj = fn_8023A0F0(arg0);
    if (obj == 0) {
        obj = fn_80239F18(arg0);
    }
    memcpy(lbl_80529CF8 + 0x1954, arg0, 6);
    if (obj != 0) {
        if (fn_803F6150(arg0, base + 0x27B4, 6) == 0) {
            memcpy(obj + 0x22, base + 0x27BA, 3);
        }
        if (obj[0x81] & 0x40) {
            if (lbl_80529CF8[0x27C0] >= 4) {
                fn_802319E4(0xD0003, base2 + 0x7FC);
            }
            fn_80244F74(arg0, base[0x197F], base + 0x1980);
            if (lbl_80529CF8[0x197B] != 0) {
                lbl_80529CF8[0x197B] = 0;
                if (lbl_80529CF8[0x27C0] >= 5) {
                    fn_802319FC(0xD0004, base2 + 0x82C, ((s32)lbl_80529CF8[0x1978] - 3) == 0);
                }
                fn_802464CC(((s32)lbl_80529CF8[0x1978] - 3) == 0);
            }
        } else if (base[0x1979] != 0 || *(void **)(base + 0x1910) == 0 ||
                   (obj[0x80] == 0 && (obj[0x23] & 0x1F) == 5 && (obj[0x24] & 0x40))) {
            var_r28 = 1;
        } else {
            memcpy(base + 0x27B4, arg0, 6);
            memcpy(base + 0x27BA, obj + 0x22, 3);
            *(void **)(base + 0x194C) = (void *)fn_80241920;
            fn_80231FB0(base + 0x193C, 0x16, 0x3C);
            ((void (*)(u8 *, u8 *, u8 *))*(void **)(base + 0x1910))(arg0, obj + 0x22, obj + 0x35);
        }
    } else {
        var_r28 = 1;
    }
    if (var_r28 != 0) {
        if (lbl_80529CF8[0x27C0] >= 2) {
            fn_80231A2C(0xD0001, base2 + 0x85C, base[0x1979], *(void **)(base + 0x1910), obj);
        }
        fn_80245158(arg0);
    }
}
