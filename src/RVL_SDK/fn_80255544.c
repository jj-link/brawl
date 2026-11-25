#pragma force_active on
#include <types.h>

extern u8 lbl_8052D5A8[0x418];
extern char lbl_8059EE28[7];
extern char lbl_8059EE30[7];
extern void fn_802319E4(int, const char *);
extern void fn_802319FC(int, const char *, int);
extern void fn_80231A14(int, const char *, int, int);
extern u8 fn_80256114(u16, u8 *, u8);
extern void *fn_8022EFF8(int);
extern void fn_8022F0E0(void *);
extern void fn_80253D7C(void *, int, void *);
extern void fn_80253E64(void *, int, int, void *);
extern void fn_80254170(void *, int, void *);
extern void fn_802542DC(void *, int, void *);
extern void fn_80254368(void *, void *);
extern void fn_8025436C(void *, void *);
extern void fn_80254374(void *, int);
extern void fn_802543D8(void *, int);
extern void fn_80254D68(void *, int, void *);
extern void fn_802553DC(void *, int, void *);

typedef struct Frame {
    u16 event;
    u16 len;
    u16 off;
    u16 ls;
    u8 buf[1];
} Frame;

u8 fn_80255544(void *context, void *header, void *packet)
{
    u8 *arg0 = context;
    u8 *arg1 = header;
    Frame *arg2 = packet;
    u8 *data;
    u8 *p;
    u8 ea;
    u8 ea2;
    int b1;
    int b2;
    u16 dlen;
    int ncnt;
    u8 fcs;
    u8 m;

    p = arg2->buf + arg2->off;
    data = p;
    if (arg2->len < 3) {
        if (lbl_8052D5A8[0x414] >= 1U) fn_802319FC(0x90000, "Bad Length1: %d", arg2->len);
        return 0x32;
    }
    ea = *p;
    b1 = ea & 1;
    arg1[2] = (ea & 2) >> 1;
    arg1[0] = *p >> 2;
    p++;
    if (b1 == 0) {
        arg1[0] = arg1[0] + (*p << 6);
        p++;
    }
    arg1[1] = *p & ~0x10;
    arg1[4] = (*p & 0x10) >> 4;
    ea2 = p[1];
    p += 2;
    b2 = ea2 & 1;
    dlen = ea2 >> 1;
    if (b2 == 0) {
        dlen = dlen + (*p << 7);
        p++;
    }
    b2 = (b2 == 0);
    b1 = (b1 == 0);
    ncnt = b1 + b2;
    arg2->len = arg2->len - (ncnt + 4);
    arg2->off = arg2->off + ncnt + 3;
    if (arg0[0x72] == 2 && arg1[1] == 0xEF && arg1[0] != 0 && arg1[4] == 1) {
        arg1[5] = *p;
        p++;
        arg2->len = arg2->len - 1;
        arg2->off = arg2->off + 1;
    } else {
        arg1[5] = 0;
    }
    if (arg2->len != dlen) {
        if (lbl_8052D5A8[0x414] >= 1U) fn_80231A14(0x90000, "Bad Length2 %d %d", arg2->len, dlen);
        return 0x32;
    }
    fcs = p[dlen];
    switch (arg1[1]) {
    case 0x2F:
        m = arg0[0x6d];
        if ((m != 0 && arg1[2] != 0) || (m == 0 && arg1[2] == 0) || arg1[4] == 0 ||
            dlen != 0 || (arg1[0] != 0 && (arg1[0] < 2U || arg1[0] > 0x3DU)) ||
            fn_80256114(3, data, fcs) == 0) {
            if (lbl_8052D5A8[0x414] >= 1U) fn_802319E4(0x90000, "Bad SABME");
            return 0x32;
        }
        return 0;
    case 0x63:
        m = arg0[0x6d];
        if ((m != 0 && arg1[2] == 0) || (m == 0 && arg1[2] != 0) || arg1[4] == 0 ||
            dlen != 0 || (arg1[0] != 0 && (arg1[0] < 2U || arg1[0] > 0x3DU)) ||
            fn_80256114(3, data, fcs) == 0) {
            if (lbl_8052D5A8[0x414] >= 1U) fn_802319E4(0x90000, lbl_8059EE28);
            return 0x32;
        }
        return 1;
    case 0x0F:
        m = arg0[0x6d];
        if ((m != 0 && arg1[2] == 0) || (m == 0 && arg1[2] != 0) ||
            dlen != 0 || (arg1[0] != 0 && (arg1[0] < 2U || arg1[0] > 0x3DU)) ||
            fn_80256114(3, data, fcs) == 0) {
            if (lbl_8052D5A8[0x414] >= 1U) fn_802319E4(0x90000, lbl_8059EE30);
            return 0x32;
        }
        return 2;
    case 0x43:
        m = arg0[0x6d];
        if ((m != 0 && arg1[2] != 0) || (m == 0 && arg1[2] == 0) || arg1[4] == 0 ||
            dlen != 0 || (arg1[0] != 0 && (arg1[0] < 2U || arg1[0] > 0x3DU)) ||
            fn_80256114(3, data, fcs) == 0) {
            if (lbl_8052D5A8[0x414] >= 1U) fn_802319E4(0x90000, "Bad DISC");
            return 0x32;
        }
        return 3;
    case 0xEF:
        if (arg1[0] != 0 && (arg1[0] < 2U || arg1[0] > 0x3DU)) {
            if (lbl_8052D5A8[0x414] >= 1U) fn_802319E4(0x90000, "Bad UIH - invalid DLCI");
            return 0x32;
        }
        if (fn_80256114(2, data, fcs) == 0) {
            if (lbl_8052D5A8[0x414] >= 1U) fn_802319E4(0x90000, "Bad UIH - FCS");
            return 0x32;
        }
        m = arg0[0x6d];
        if ((m != 0 && arg1[2] != 0) || (m == 0 && arg1[2] == 0)) {
            if (lbl_8052D5A8[0x414] >= 1U) fn_802319E4(0x90000, "Bad UIH - response");
            return 4;
        }
        return 4;
    default:
        return 0x32;
    }
}

void fn_80255AB8(void *arg0, void *arg1)
{
    u8 flag;
    u8 *packet = arg1;
    u8 *base = lbl_8052D5A8;
    u8 *p;
    u8 *out;
    u8 encoded;
    u8 decoded;
    unsigned int len;
    u8 value;
    u8 address;
    u8 bit;

    len = *(u16 *)(packet + 2);
    p = (0, packet + *(u16 *)(packet + 4));
    base[3] = p[8] & 1;
    flag = (p[8] >> 1) & 1;
    base[2] = flag;
    base[1] = p[8] & 0xFC;
    if (base[3] == 0 || len == 0) {
        if (lbl_8052D5A8[0x414] >= 1) {
            fn_80231A14(0x90000, "Illegal MX Frame ea:%d len:%d", base[3], len);
        }
        fn_8022F0E0(arg1);
        return;
    }
    encoded = p[9];
    p += 10;
    decoded = encoded >> 1;
    len += 0xFFFE;
    if (!(encoded & 1)) {
        len--;
        decoded = (u8)(decoded + (*(p++) << 7));
    }
    if ((u8)decoded != (u16)len) {
        if (lbl_8052D5A8[0x414] >= 1) {
            fn_802319E4(0x90000, "Bad MX frame");
        }
        fn_8022F0E0(arg1);
        return;
    }
    switch (base[1]) {
    case 0x80:
        if ((u16)len != 8) {
            break;
        }
        address = p[0] & 0x3F;
        base[0] = address;
        base[9] = p[1] & 0x0F;
        base[10] = p[1] & 0xF0;
        base[11] = p[2] & 0x3F;
        base[12] = p[3];
        *(u16 *)(base + 14) = p[4] + (p[5] << 8);
        base[16] = p[6];
        base[17] = p[7] & 7;
        if (address == 0 || (address != 0 && (address < 2 || address > 0x3D)) ||
            *(u16 *)(base + 14) < 0x17 || *(u16 *)(base + 14) > 0x7FFF) {
            if (lbl_8052D5A8[0x414] >= 1) {
                fn_802319E4(0x90000, "Bad PN frame");
            }
            break;
        }
        fn_8022F0E0(arg1);
        fn_80253D7C(arg0, flag, base);
        return;

    case 0x20:
        if ((u16)len == 0) {
            break;
        }
        *(u8 **)(base + 8) = p;
        *(u16 *)(base + 12) = len;
        *(u16 *)(packet + 4) += 2;
        *(u16 *)(packet + 2) -= 2;
        if (flag) {
            fn_802553DC(arg0, 0, arg1);
        } else {
            fn_8025436C(arg0, arg1);
        }
        return;

    case 0xA0:
        if ((u16)len != 0) {
            break;
        }
        fn_8022F0E0(arg1);
        fn_80254374(arg0, flag);
        return;

    case 0x60:
        if ((u16)len != 0) {
            break;
        }
        fn_8022F0E0(arg1);
        fn_802543D8(arg0, flag);
        return;

    case 0xE0:
        value = p[0];
        bit = (value & 2) >> 1;
        address = value >> 2;
        base[0] = address;
        if (!(value & 1) || !bit || address == 0 ||
            (address != 0 && (address < 2 || address > 0x3D))) {
            if (lbl_8052D5A8[0x414] >= 1) {
                fn_802319E4(0x90000, "Bad MSC frame");
            }
            break;
        }
        base[9] = p[1];
        if ((u8)decoded == 3) {
            base[10] = p[2] & 2;
            base[11] = (p[2] >> 4) & 15;
        } else {
            base[10] = 0;
            base[11] = 0;
        }
        fn_8022F0E0(arg1);
        fn_80254170(arg0, flag, base);
        return;

    case 0x10:
        if ((u16)len != 1 || !flag) {
            break;
        }
        base[8] = p[0] & 1;
        base[9] = (p[0] & 2) >> 1;
        base[10] = p[0] >> 2;
        fn_8022F0E0(arg1);
        fn_80254368(arg0, base);
        return;

    case 0x90:
        if ((u16)len != 1 && (u16)len != 8) {
            break;
        }
        value = p[0];
        bit = (value & 2) >> 1;
        address = value >> 2;
        base[0] = address;
        if (!(value & 1) || !bit || address == 0 ||
            (address != 0 && (address < 2 || address > 0x3D))) {
            if (lbl_8052D5A8[0x414] >= 1) {
                fn_802319E4(0x90000, "Bad RPN frame\0\0");
            }
            break;
        }
        base[9] = (u16)len == 1;
        if (!base[9]) {
            base[10] = p[1];
            base[11] = p[2] & 3;
            base[12] = (p[2] >> 2) & 1;
            base[13] = (p[2] >> 3) & 1;
            base[14] = (p[2] >> 4) & 3;
            base[15] = p[3] & 0x3F;
            base[16] = p[4];
            base[17] = p[5];
            *(u16 *)(base + 18) = (p[6] + (p[7] << 8)) & 0x3F7F;
        }
        fn_8022F0E0(arg1);
        fn_80253E64(arg0, flag, base[9], base);
        return;

    case 0x50:
        if ((u16)len != 2) {
            break;
        }
        value = p[0];
        bit = (value & 2) >> 1;
        address = value >> 2;
        base[0] = address;
        base[9] = p[1] & 0xFE;
        if (!(value & 1) || !bit || address == 0 ||
            (address != 0 && (address < 2 || address > 0x3D))) {
            if (lbl_8052D5A8[0x414] >= 1) {
                fn_802319E4(0x90000, "Bad RPN frame\0\0");
            }
            break;
        }
        fn_8022F0E0(arg1);
        fn_802542DC(arg0, flag, base);
        return;
    }

    fn_8022F0E0(arg1);
    if (flag) {
        out = fn_8022EFF8(2);
        if (out != 0) {
            *(u16 *)(out + 4) = 12;
            out[20] = 0x11;
            out[21] = 3;
            out[22] = lbl_8052D5A8[1] | (lbl_8052D5A8[3] | (lbl_8052D5A8[2] << 1));
            *(u16 *)(out + 2) = 3;
            fn_80254D68(arg0, 0, out);
        }
    }
}
