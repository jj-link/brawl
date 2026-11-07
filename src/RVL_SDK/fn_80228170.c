#pragma force_active on
extern unsigned char lbl_804F9FC0[], lbl_8047E234[];
extern float lbl_805A39E8, lbl_805A39F8, lbl_805A3A00, lbl_805A3A40, lbl_805A3A44;
extern int fn_8021A024(int, int *);
extern void fn_8021A920(int, unsigned char *);
extern int fn_8021A1E8(int);
extern unsigned char fn_80218DB0(void);
extern double fn_80400D94(float);
extern int fn_8021C938(int);
extern int fn_8021C9AC(int, unsigned char, void (*)(void));
extern void fn_80228448(void);
extern void fn_8021A230(int, unsigned char);
void fn_80228170(int arg)
{
    unsigned char *p = lbl_804F9FC0 + arg * 0x528;
    unsigned char *table;
    unsigned int index;
    int kind, mode;
    unsigned char current;
    float value, y, x, length;
    if (fn_8021A024(arg, &kind) != -1) {
        unsigned char *entry;
        index = p[0x10e];
        if (index >= 16) index = 0;
        entry = p + 0x110 + index * 0x38;
        fn_8021A920(arg, entry);
        entry[0x36] = fn_8021A1E8(arg);
        p[0x10e] = index + 1;
        if (p[0x10f] < 16) p[0x10f]++;
        if (p[0x524]) {
            if (p[0x525]) {
                if (fn_80218DB0() == 1) value = lbl_805A3A40;
                else value = lbl_805A3A44;
            } else value = lbl_805A39E8;
            x = lbl_805A39F8;
            y = lbl_805A3A00;
            *(float *)(p + 0xb8) = lbl_805A39E8;
            *(float *)(p + 0xbc) = -value;
            length = (float)fn_80400D94(x * x + y * y);
            value = *(float *)(p + 0xb8);
            if (value < lbl_805A39E8) x += value;
            else x -= value;
            value = *(float *)(p + 0xbc);
            if (value < lbl_805A39E8) y += value;
            else y -= value;
            x = x < y ? x : y;
            *(float *)(p + 0xc0) = length / x;
            p[0x524] = 0;
        }
        switch (kind) {
        case 0: case 0xfb: case 0xfc: case 0xff: mode = 0; break;
        case 1: mode = 2; break;
        case 2: mode = 4; break;
        default: goto end;
        }
        if (p[0x520]) mode++;
        if (fn_8021C938(arg)) current = p[0x521];
        else current = 0;
        table = lbl_8047E234 + mode * 2;
        if (current != table[0]) {
            if (*(void (**)(int,int))(p + 0x4d8) && !p[0x522]) {
                p[0x522] = 1;
                (*(void (**)(int,int))(p + 0x4d8))(arg, 0);
                p[0x523] = 0;
            }
            if (!p[0x51f]) {
                p[0x51f] = 1;
                if (!fn_8021C9AC(arg, table[0], fn_80228448)) p[0x521] = table[0];
            }
        } else if (entry[0x36] != table[1]) fn_8021A230(arg, table[1]);
    }
end:
    if (*(void (**)(int))(p + 0x518)) (*(void (**)(int))(p + 0x518))(arg);
}