#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef void (*Callback)(int *);
extern Callback fn_803C6C90(void);
extern void fn_801E1D80(s64, OSCalendarTime *);

void fn_803C7318(short *date, short *time) {
    OSCalendarTime cal;
    int values[6];
    Callback callback = fn_803C6C90();
    date[0] = 0;
    date[1] = 0;
    date[2] = 0;
    time[0] = 0;
    time[1] = 0;
    time[2] = 0;
    if (callback) {
        callback(values);
        date[0] = values[5];
        date[1] = values[4];
        date[2] = values[3];
        time[0] = values[2];
        time[1] = values[1];
        time[2] = values[0];
    } else {
        fn_801E1D80(OSGetTime(), &cal);
        date[0] = cal.year;
        date[1] = cal.month + 1;
        date[2] = cal.mday;
        time[0] = cal.hour;
        time[1] = cal.min;
        time[2] = cal.sec;
    }
}