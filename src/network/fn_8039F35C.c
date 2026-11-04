#include <types.h>
#pragma force_active on

typedef struct {
    u16 year;
    u8 month, day, hour, second, minute, extra;
} Date;
typedef struct {
    s32 second, minute, hour, day, month, year;
    s32 rest[3];
} Calendar;
typedef struct {
    u32 x0, flags;
    s32 size;
    char padding[0x1c];
    s32 time;
    s32 offset;
} Context;

extern void fn_80399CD4(Date *);
extern void fn_8038EC6C(Calendar *);
extern s32 fn_803A129C(void *, const Date *);
extern s32 fn_803A1344(Date *, s32);
extern void *fn_80397748(void *, unsigned char, unsigned long);
extern int fn_80397DE0(void *, const char *, ...);
extern s32 fn_80397640(void *);
extern s32 fn_80398BD8(void *, s32, s32);
extern void *lbl_805A1170;
extern s32 lbl_805A1190;
extern const char *lbl_80492188[];
extern char lbl_804921B8[];

s32 fn_8039F35C(Context *ctx)
{
    Date date;
    Calendar cal;
    void *buf;
    s32 len;
    s32 result;

    fn_80399CD4(&date);
    fn_8038EC6C(&cal);
    date.year = cal.year;
    date.month = cal.month + 1;
    date.day = cal.day;
    date.hour = cal.hour;
    date.minute = cal.minute;
    date.second = cal.second;
    if (date.month > 12)
        return -24;
    fn_803A129C(&ctx->time, &date);
    if (ctx->flags & 0x01000000)
        fn_803A1344(&date, ctx->offset);
    buf = lbl_805A1170;
    fn_80397748(buf, 0, 0x400);
    fn_80397DE0(buf, lbl_804921B8, date.day, lbl_80492188[date.month - 1],
                date.year, date.hour, date.minute, date.second);
    len = fn_80397640(buf);
    result = fn_80398BD8(buf, len, lbl_805A1190);
    if (result == 0)
        ctx->size += len;
    return result;
}