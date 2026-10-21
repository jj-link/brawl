#pragma force_active on
extern int strncmp(const char *, const char *, unsigned long);
extern char *strstr(const char *, const char *);
extern int atoi(const char *);
extern int fn_80372F14(const char *, const char *, void *, int);
extern void fn_8036AAF0(void *, int, int);

extern char lbl_8059F968[8];
extern char lbl_8059F970[6];
extern char lbl_8048FB60[9];
extern char lbl_8059F978[8];

typedef struct Data {
    char text[0x434];
    int value;
} Data;

static int normalize(int value)
{
    return value != 0;
}

int fn_80372E1C(Data **arg0, const char *arg1, int arg2)
{
    char buf[16];
    Data *data = *arg0;

    if (strncmp(arg1, lbl_8059F968, 7) == 0) {
        if (fn_80372F14(arg1, lbl_8059F970, buf, 16) != 0) {
            data->value = atoi(buf);
        }

        if (fn_80372F14(arg1, lbl_8048FB60, data, 0x100) == 0) {
            data->text[0] = 0;
        }

        if (arg2 != 0) {
            fn_8036AAF0(arg0, 4,
                       normalize(strstr(arg1, lbl_8059F978) != 0));
        }

        return 1;
    }

    return 0;
}
