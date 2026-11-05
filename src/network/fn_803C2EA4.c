#pragma force_active on
extern void fn_803C7318(short *, short *);

void fn_803C2EA4(short *date, short *time) {
    date[0] = 2000;
    date[1] = 4;
    date[2] = 1;
    time[0] = 0;
    time[1] = 0;
    time[2] = 0;
    time[3] = 1;
    fn_803C7318(date, time);
    time[3] = 1;
}
