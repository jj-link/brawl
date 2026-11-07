#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_80416918[];
extern u16 lbl_80416928[];

static int IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int fn_803A1678(u32 year, u32 month, u32 day) {
    u32 days;
    int y;
    u32 total;

    if (year < 1900 || month < 1 || month > 12) {
        return -1;
    }
    if (month == 2 && IsLeapYear(year)) {
        if (day < 1 || day > 29) {
            return -1;
        }
    } else {
        if (day < 1 || lbl_80416918[month - 1] < day) {
            return -1;
        }
    }
    days = day - 1;
    days += lbl_80416928[month - 1];
    if (month >= 3 && IsLeapYear(year)) {
        days++;
    }
    y = year - 1900;
    days += y * 365;
    total = days + (y + 299) / 400;
    y--;
    return y / 4 - y / 100 + total;
}
