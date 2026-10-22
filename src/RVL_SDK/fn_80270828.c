#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed long s32;
struct T { u8 pad[0xB4]; u16 *tbl[7][6]; };
struct H { u8 pad[8]; u16 *str; };
struct A { u8 pad[4]; struct H *h; };

void fn_80270828(struct T *arg0) {
    s32 col;
    s32 i;
    s32 row;
    s32 in;
    u16 *s;

    i = 0;
    row = 0;
    in = 0;
    s = ((struct A *)arg0)->h->str;
    col = 0;
    while (s[i] != 0) {
        if (s[i] == 0x22) {
            if (in == 0) {
                arg0->tbl[row][col] = s + (i + 1);
                row += 1;
                in = 1;
                if (row == 7) {
                    row = 0;
                    col += 1;
                }
            } else {
                in = 0;
            }
        }
        i += 1;
    }
}
