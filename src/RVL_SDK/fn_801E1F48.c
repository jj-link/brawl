#include <revolution/OS/OSTime.h>
#pragma force_active on

#define MONTH_MAX 12
#define SECS_IN_MIN 60
#define SECS_IN_HOUR (SECS_IN_MIN * 60)
#define SECS_IN_DAY (SECS_IN_HOUR * 24)
#define SECS_IN_YEAR (SECS_IN_DAY * 365)

extern s32 lbl_80468C68[MONTH_MAX];
extern s32 lbl_80468C98[MONTH_MAX];

static BOOL IsLeapYear(s32 year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static s32 GetLeapDays(s32 year) {
    if (year < 1) {
        return 0;
    }
    return (year + 3) / 4 - (year - 1) / 100 + (year - 1) / 400;
}

s64 OSCalendarTimeToTicks(const OSCalendarTime* cal) {
    s64 seconds;
    s32 month;
    s32 ovMon;
    s32 leapDays;
    s32 year;
    s32* yearDays;

    ovMon = cal->month / MONTH_MAX;
    month = cal->month - (ovMon * MONTH_MAX);

    if (month < 0) {
        month += MONTH_MAX;
        ovMon--;
    }

    year = cal->year + ovMon;

    leapDays = GetLeapDays(year);

    yearDays = IsLeapYear(year) ? lbl_80468C98 : lbl_80468C68;

    seconds = (s64)SECS_IN_YEAR * year +
              (s64)SECS_IN_DAY * (cal->mday + leapDays + yearDays[month] - 1) +
              (s64)SECS_IN_HOUR * cal->hour +
              (s64)SECS_IN_MIN * cal->min +
              cal->sec -
              (s64)0xEB1E1BF80ULL;

    return OS_SEC_TO_TICKS(seconds) + OS_MSEC_TO_TICKS((s64)cal->msec) +
           OS_USEC_TO_TICKS((s64)cal->usec);
}
