#pragma force_active on
extern int lbl_805A0AD8;
extern int lbl_805A0ADC;
extern int lbl_805A0AE0;
extern int lbl_805A0AE4;
extern int lbl_805A0AE8;
extern int lbl_805A0AEC;
extern int lbl_805A0AF0;
extern int lbl_805A0AF4;
extern int lbl_805A0AF8;
extern int lbl_805A0AFC;
extern int lbl_805A0B00;
extern int lbl_805A0B04;
extern int lbl_805A0B08;
extern int lbl_805A0B0C;
extern int lbl_805A0B10;
extern int lbl_805A0B14;
extern int lbl_805A0B18;
extern int lbl_805A0B1C;
extern int lbl_805A0B20;
extern int lbl_805A0B24;

void fn_8020151C(void *arg0) {
    char *p = (char *)arg0;
    lbl_805A0B24 += *(short *)(p + 0x52);
    lbl_805A0B18 += *(short *)(p + 0x54);
    lbl_805A0B0C += *(short *)(p + 0x56);
    lbl_805A0B00 += *(short *)(p + 0x58);
    lbl_805A0B20 += *(short *)(p + 0x5A);
    lbl_805A0B14 += *(short *)(p + 0x5C);
    lbl_805A0B08 += *(short *)(p + 0x5E);
    lbl_805A0AFC += *(short *)(p + 0x60);
    lbl_805A0B1C += *(short *)(p + 0x62);
    lbl_805A0B10 += *(short *)(p + 0x64);
    lbl_805A0B04 += *(short *)(p + 0x66);
    lbl_805A0AF8 += *(short *)(p + 0x68);
    lbl_805A0AF4 += *(short *)(p + 0xFA);
    lbl_805A0AF0 += *(short *)(p + 0xFC);
    lbl_805A0AEC += *(short *)(p + 0xFE);
    lbl_805A0AE8 += *(short *)(p + 0x100);
    lbl_805A0AE4 += *(short *)(p + 0x102);
    lbl_805A0AE0 += *(short *)(p + 0x104);
    lbl_805A0ADC += *(short *)(p + 0x106);
    lbl_805A0AD8 += *(short *)(p + 0x108);
}
