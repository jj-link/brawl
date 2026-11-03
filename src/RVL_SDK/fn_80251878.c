#pragma force_active on
#pragma opt_propagation off

extern char lbl_804841C8[];
extern unsigned char lbl_8052D5A8[];
extern int fn_80239200(char *);
extern void fn_802319E4(int, char *);
extern void fn_802319FC();
extern void fn_80231A2C(int, char *, int, int, int);

void fn_80251878(char *p)
{
    char *base;
    unsigned short r;
    int val;
    int result;
    int temp;
    int d1;
    int d2;
    int d3;
    unsigned short v;

    base = lbl_804841C8;
    val = *(unsigned short *)(p + 0x12);
    if (val == 0) {
        result = fn_80239200(p + 6);
        r = (unsigned short)result;
        if (r == 0) {
            if (lbl_8052D5A8[0x414] >= 2) {
                fn_802319E4(0x90001, "port_select_mtu bad packet size");
            }
            *(unsigned short *)(p + 0x12) = 0x7F;
        } else if (r <= 0x69F) {
            temp = 0x69F / (int)r * result - 0xA;
            *(unsigned short *)(p + 0x12) = (unsigned short)temp;
            if (lbl_8052D5A8[0x414] >= 5) {
                fn_802319FC(0x90004, "port_select_mtu selected %d based on connection speed", (unsigned short)temp);
            }
        } else {
            *(unsigned short *)(p + 0x12) = 0x695;
            if (lbl_8052D5A8[0x414] >= 5) {
                fn_802319FC(0x90004, "port_select_mtu selected %d based on l2cap PDU size", 0x695);
            }
        }
    } else {
        if (lbl_8052D5A8[0x414] >= 5) {
            fn_802319FC(0x90004, "port_select_mtu application selected %d", val);
        }
    }

    v = *(unsigned short *)(p + 0x12);
    d1 = 8000 / v;
    d2 = 5000 / v;
    d3 = 12000 / v;
    *(unsigned short *)(p + 0x9C) = (unsigned short)d1;
    *(unsigned short *)(p + 0x9E) = (unsigned short)d2;
    *(unsigned short *)(p + 0xA0) = (unsigned short)d3;
    if (lbl_8052D5A8[0x414] >= 5) {
        fn_80231A2C(0x90004, "port_select_mtu credit_rx_max %d, credit_rx_low %d, rx_buf_critical %d",
                    (unsigned short)d1,
                    (unsigned short)d2,
                    (unsigned short)d3);
    }
}