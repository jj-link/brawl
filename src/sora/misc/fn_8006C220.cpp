#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;

extern u16 lbl_804075C8[];

struct Tbl {
    u16 v[0x5E];
};

extern "C" s32 fn_8006C220(u8* out, u8* in) {
    Tbl tbl;
    u8* o = out;
    u8* start;
    u8 c;
    u8 next;

    tbl = *(Tbl*)lbl_804075C8;
    start = in;
    do {
        c = *in;
        if ((s8)c < 0x21 || (s8)c >= 0x7F) {
            *o = c;
            o++;
        } else {
            u8 hi;
            u16 w;
            switch ((s8)c) {
            case 0x22:
            case 0x27:
            case 0x2D:
                hi = 0xE2;
                break;
            default:
                hi = 0xEF;
                break;
            }
            w = tbl.v[(s8)c - 0x21];
            o[0] = hi;
            o[1] = (u8)(w >> 8);
            o[2] = (u8)w;
            o += 3;
        }
        next = *in;
        in++;
    } while ((s8)next != 0);
    return (s32)(in - start);
}
