#include <revolution/types.h>
#include <revolution/DWC/dwc_nastime.h>

#pragma force_active on

typedef struct {
    s32 sec;
    s32 min;
    s32 hour;
    s32 mday;
    s32 month;
    s32 year;
    s32 wday;
    s32 yday;
} DST;

extern u64 fn_8034F57C(void);
extern BOOL fn_80352B78(u64 *out);
extern DST *fn_8034F5C4(u64 *arg);

BOOL DWC_GetDateTime(DWCDate *date, DWCTime *time) {
    u64 t2;
    u64 t1;
    BOOL ret;
    DST *dst;
    t1 = fn_8034F57C();
    ret = fn_80352B78(&t2);
    if (ret != 0) {
        t1 += t2;
    }
    dst = fn_8034F5C4(&t1);
    date->year = dst->year + 0x76C;
    date->month = dst->month;
    date->mday = dst->mday;
    date->yday = dst->yday;
    date->wday = dst->wday;
    time->hour = dst->hour;
    time->min = dst->min;
    time->sec = dst->sec;
    time->msec = 0;
    time->usec = 0;
    return ret;
}