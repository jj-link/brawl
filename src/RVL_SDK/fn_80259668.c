#pragma force_active on
#include <types.h>
#include <string.h>

typedef struct {
    u8 pad0[2];
    u8 mtu_present;
    u8 pad3;
    u16 mtu;
    u8 pad6[0x1A];
    u8 flush_to_present;
    u8 pad21;
    u16 flush_to;
    u8 pad24[0x4604 - 0x24];
    void *reg_info[10];
    u16 max_attr_list_size;
    u16 max_recs_per_search;
    u8 trace_level;
    u8 pad4631[0xF];
} SdpCb;

typedef struct Config {
    u16 a;
    u8 b;
    u8 pad;
    u16 mtu;
    u8 pad2[26];
    u8 c;
} Config;

typedef struct Object {
    u8 state;
    u8 flags;
    u8 addr[6];
    u8 timer[0x18];
    u16 mtu;
    u16 cid;
    u8 pad24[0x3F0];
    void (*callback)(u16);
} Object;

extern SdpCb lbl_8052D9C0;

extern u8 fn_8023F558(int, char *, u8, int, u16, u32, int);
extern void fn_802319E4(int, const char *);
extern void fn_802319FC(int, const char *, int);
extern void fn_80231A14(int, const char *, int, int);
extern void fn_80231FB0(void *, int, int);
extern u8 fn_8024A304(int, void **);
extern u16 fn_8024A530(int, void *);
extern void fn_8024A764(void *, unsigned int, unsigned short, unsigned int, unsigned int);
extern void fn_8024A8F4(int, void *);
extern void fn_8024A9AC(int, Config *);
extern void fn_8024AA7C(u16);
extern void fn_8024AB20(int);
extern void fn_8025860C(void *);
extern void fn_80258640(void *, s32);
extern void fn_8025A1D4(void *, s32);
extern Object *fn_8025AEE4(int);
extern void *fn_8025AF74(void);
extern void fn_8025AFE8(void *);
extern void fn_8022F0E0(s32);
extern void fn_8025A090(void);

void fn_80259808(void *arg0, unsigned short arg1, int arg2, unsigned int arg3);
void fn_802598CC(int arg0, unsigned arg1);
void fn_80259A5C(int arg0, Config *arg1);
void fn_80259B98(int arg0, u16 *arg1);
void fn_80259D14(int arg0, int arg1);
void fn_80259E0C(s32 arg0, s32 arg1);

void fn_80259668(void) {
    int zero;

    memset(&lbl_8052D9C0, 0, 0x4634);
    lbl_8052D9C0.mtu_present = 1;
    lbl_8052D9C0.mtu = 0x100;
    zero = (u8)((lbl_8052D9C0.flush_to_present = 1) - 1);
    lbl_8052D9C0.flush_to = 0xFFFF;
    lbl_8052D9C0.max_attr_list_size = 0xF0;
    lbl_8052D9C0.max_recs_per_search = 0x15;

    if (fn_8023F558(0, "Service Discovery", 0, 0, 1, 0, 0) == 0) {
        if (lbl_8052D9C0.trace_level >= 1)
            fn_802319E4(0xA0000, "Security Registration Server failed");
        return;
    }
    if (fn_8023F558(1, "Service Discovery", 0, 0, 1, 0, 0) == 0) {
        if (lbl_8052D9C0.trace_level >= 1)
            fn_802319E4(0xA0000, "Security Registration for Client failed");
        return;
    }
    lbl_8052D9C0.trace_level = (u8)zero;
    lbl_8052D9C0.reg_info[0] = (void *)fn_80259808;
    lbl_8052D9C0.reg_info[1] = (void *)fn_802598CC;
    lbl_8052D9C0.reg_info[2] = (void *)zero;
    lbl_8052D9C0.reg_info[3] = (void *)fn_80259A5C;
    lbl_8052D9C0.reg_info[4] = (void *)fn_80259B98;
    lbl_8052D9C0.reg_info[5] = (void *)fn_80259D14;
    lbl_8052D9C0.reg_info[6] = (void *)fn_8025A090;
    lbl_8052D9C0.reg_info[7] = (void *)zero;
    lbl_8052D9C0.reg_info[8] = (void *)fn_80259E0C;
    lbl_8052D9C0.reg_info[9] = (void *)zero;
    if (fn_8024A304(1, lbl_8052D9C0.reg_info) == 0) {
        if (lbl_8052D9C0.trace_level >= 1)
            fn_802319E4(0xA0000, "SDP Registration failed");
    }
}

void fn_80259808(void *arg0, unsigned short arg1, int arg2, unsigned int arg3) {
    Object *obj = fn_8025AF74();
    if (obj != 0) {
        obj->state = 2;
        memcpy(obj->addr, arg0, 6);
        obj->cid = arg1;
        fn_8024A764(arg0, arg3, arg1, 0, 0);
        fn_8024A8F4(arg1, &lbl_8052D9C0);
        if (lbl_8052D9C0.trace_level >= 4)
            fn_802319FC(0xA0003, "SDP - Rcvd L2CAP conn ind, sent config req, CID 0x%x", obj->cid);
    }
}

void fn_802598CC(int arg0, unsigned arg1)
{
    Object *obj = fn_8025AEE4(arg0);

    if (obj == 0) {
        if (lbl_8052D9C0.trace_level >= 2U) {
            fn_802319FC(0xA0001, "SDP - Rcvd conn cnf for unknown CID 0x%x", arg0);
        }
    } else if (arg1 == 0 && obj->state == 1) {
        obj->state = 2;
        fn_8024A8F4(arg0, &lbl_8052D9C0);
        if (lbl_8052D9C0.trace_level >= 4U) {
            fn_802319FC(0xA0003, "SDP - got conn cnf, sent cfg req, CID: 0x%x", obj->cid);
        }
    } else {
        if (lbl_8052D9C0.trace_level >= 2U) {
            fn_80231A14(0xA0001, "SDP - Rcvd conn cnf with error: 0x%x  CID 0x%x", arg1, obj->cid);
        }
        if (obj->callback != 0) {
            if (arg1 == 14 || arg1 == 5 || arg1 == 24 || arg1 == 41 || arg1 == 6) {
                obj->callback(0xFFF6);
            } else if (arg1 == 15) {
                obj->callback(0xFFF7);
            } else {
                obj->callback(0xFFF1);
            }
        }
        fn_8025AFE8(obj);
    }
}

void fn_80259A5C(int arg0, Config *arg1)
{
    Object *obj = fn_8025AEE4(arg0);
    if (obj == 0) {
        if (lbl_8052D9C0.trace_level >= 2U) {
            fn_802319FC(0xA0001, "SDP - Rcvd L2CAP cfg ind, unknown CID: 0x%x", arg0);
        }
    } else {
        if (arg1->b == 0) {
            obj->mtu = 0x100;
        } else if (arg1->mtu > 0x100U) {
            obj->mtu = 0x100;
        } else {
            obj->mtu = arg1->mtu;
        }
        arg1->c = 0;
        arg1->b = 0;
        arg1->a = 0;
        fn_8024A9AC(arg0, arg1);
        if (lbl_8052D9C0.trace_level >= 4U) {
            fn_802319FC(0xA0003, "SDP - Rcvd cfg ind, sent cfg cfm, CID: 0x%x", arg0);
        }
        obj->flags |= 2;
        if (obj->flags & 4) {
            obj->state = 3;
            if (obj->flags & 1) {
                fn_8025860C(obj);
            } else {
                fn_80231FB0((u8 *)obj + 8, 5, 30);
            }
        }
    }
}

void fn_80259B98(int arg0, u16 *arg1) {
    u8 *obj;
    void (*callback)(u16);
    u8 flags;

    if (lbl_8052D9C0.trace_level >= 4U) {
        fn_80231A14(0xA0003, "SDP - Rcvd cfg cfm, CID: 0x%x  Result: %d", arg0, *arg1);
    }
    obj = (u8 *)fn_8025AEE4(arg0);
    if (obj == 0) {
        if (lbl_8052D9C0.trace_level >= 2U) {
            fn_802319FC(0xA0001, "SDP - Rcvd L2CAP cfg ind, unknown CID: 0x%x", arg0);
        }
    } else if (*arg1 == 0) {
        flags = obj[1] | 4;
        obj[1] = flags;
        if (flags & 2) {
            obj[0] = 3;
            if (obj[1] & 1) {
                fn_8025860C(obj);
            } else {
                fn_80231FB0(obj + 8, 5, 0x1E);
            }
        }
    } else {
        if (lbl_8052D9C0.trace_level >= 4U) {
            fn_802319FC(0xA0003, "SDP - disconnect  CID: 0x%x", *(u16 *)(obj + 0x22));
        }
        if (obj[0] != 1U) {
            fn_8024AA7C(*(u16 *)(obj + 0x22));
            *(u16 *)(obj + 0x472) = 0xFFF2;
        } else {
            callback = *(void (**)(u16))(obj + 0x414);
            if (callback != 0) {
                callback(0xFFF2);
            }
            fn_8025AFE8(obj);
        }
    }
}

void fn_80259D14(int arg0, int arg1)
{
    Object *obj = fn_8025AEE4(arg0);

    if (obj == 0) {
        if (lbl_8052D9C0.trace_level >= 2U) {
            fn_802319FC(0xA0001, "SDP - Rcvd L2CAP disc, unknown CID: 0x%x", arg0);
        }
    } else {
        if (arg1 != 0) {
            fn_8024AB20(arg0);
        }

        if (lbl_8052D9C0.trace_level >= 4U) {
            fn_802319FC(0xA0003, "SDP - Rcvd L2CAP disc, CID: 0x%x", arg0);
        }

        if (obj->callback != 0) {
            obj->callback(obj->state == 3 ? 0 : 0xFFF1);
        }

        fn_8025AFE8(obj);
    }
}

void fn_80259E0C(s32 arg0, s32 arg1)
{
    Object *obj = fn_8025AEE4(arg0);

    if (obj != 0) {
        if (obj->state == 3) {
            if (obj->flags & 1) {
                fn_80258640(obj, arg1);
            } else {
                fn_8025A1D4(obj, arg1);
            }
        } else if (lbl_8052D9C0.trace_level >= 2U) {
            fn_80231A14(0xA0001, "SDP - Ignored L2CAP data while in state: %d, CID: 0x%x", obj->state, arg0);
        }
    } else if (lbl_8052D9C0.trace_level >= 2U) {
        fn_802319FC(0xA0001, "SDP - Rcvd L2CAP data, unknown CID: 0x%x", arg0);
    }

    fn_8022F0E0(arg1);
}

void *fn_80259EE0(void *arg0) {
    u8 *obj;
    u16 result;

    obj = fn_8025AF74();
    if (obj == 0) {
        if (lbl_8052D9C0.trace_level >= 2U) {
            fn_802319E4(0xA0001, "SDP - no spare CCB for orig");
        }
        return 0;
    }
    if (lbl_8052D9C0.trace_level >= 4U) {
        fn_802319E4(0xA0003, "SDP - Originate started");
    }
    obj[1] |= 1;
    memcpy(obj + 2, arg0, 6);
    obj[0] = 1;
    result = fn_8024A530(1, arg0);
    if (result != 0) {
        *(u16 *)(obj + 0x22) = result;
        return obj;
    }
    if (lbl_8052D9C0.trace_level >= 2U) {
        fn_802319E4(0xA0001, "SDP - Originate failed\0");
    }
    fn_8025AFE8(obj);
    return 0;
}

void fn_80259FF4(u8 *arg0, s16 arg1) {
    void (*temp_r12)(s16);

    if (lbl_8052D9C0.trace_level >= 4U) {
        fn_802319FC(0xA0003, "SDP - disconnect  CID: 0x%x", *(u16 *)(arg0 + 0x22));
    }
    if (arg0[0] != 1U) {
        fn_8024AA7C(*(u16 *)(arg0 + 0x22));
        *(s16 *)(arg0 + 0x472) = arg1;
        return;
    }
    temp_r12 = *(void (**)(s16))(arg0 + 0x414);
    if (temp_r12 != 0) {
        temp_r12(arg1);
    }
    fn_8025AFE8(arg0);
}
