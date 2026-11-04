#pragma force_active on
typedef unsigned char u8;
typedef struct { char buffer[0x578]; int len; } Buffer;
typedef struct { int keytype, packetnum, keyindex, count, index; u8 keys[0x100]; int numkeys; } SplitState;
extern int fn_80379D50(int *, Buffer *, SplitState *);
extern void fn_80379A3C(int *, Buffer *, int, u8, u8 *);
extern int sendto(int, const void *, unsigned int, int, const void *, unsigned int);

void fn_8037A0A0(int *qrec, Buffer *buf, u8 *data, int len, void *addr) {
    u8 flags = 0;
    u8 n0, n1, n2;
    u8 *p0 = 0;
    u8 *p1 = 0;
    u8 *p2 = 0;
    SplitState st;
    if (len < 3) return;
    n0 = *data++;
    len--;
    if (n0 != 0 && n0 != 255) {
        p0 = data;
        data += n0;
        len -= n0;
    }
    if (len < 2) return;
    n1 = *data++;
    len--;
    if (n1 != 0 && n1 != 255) {
        p1 = data;
        data += n1;
        len -= n1;
    }
    if (len < 1) return;
    n2 = *data++;
    len--;
    if (n2 != 0 && n2 != 255) {
        p2 = data;
        data += n2;
        len -= n2;
    }
    if (len < 0) return;
    if (len > 0) flags = *data;
    if ((flags & 1) == 1) {
        st.packetnum = 0;
        st.keytype = 0;
        st.keyindex = 0;
        st.count = 0;
        st.index = 0;
        st.numkeys = 0;
        while (fn_80379D50(qrec, buf, &st) == 1) {
            sendto(*qrec, buf, buf->len, 0, addr, 8);
            buf->len = 5;
            if (st.packetnum > 7) return;
        }
    } else {
        fn_80379A3C(qrec, buf, 0, n0, p0);
        fn_80379A3C(qrec, buf, 1, n1, p1);
        fn_80379A3C(qrec, buf, 2, n2, p2);
        sendto(*qrec, buf, buf->len, 0, addr, 8);
    }
}