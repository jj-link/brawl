#pragma force_active on
typedef unsigned long long u64;

typedef struct {
    char pad[0x10];
    u64 time;
} State;

extern char lbl_8059F860[8];
extern char lbl_8048F634[14];

extern unsigned int strlen(const char *);
extern int sprintf(char *, const char *, ...);
extern int fn_8036A680(int, State *, const char *);
extern int fn_8036A594(int, State *, const char *, int);
extern int fn_8036A4E8(int, State *, int);
extern u64 fn_8035D258(int);

int fn_803702DC(int arg0, State *arg1, const char *arg2, int arg3)
{
    char buffer[32];
    int ret;

    if (arg2 == 0) {
        arg2 = lbl_8059F860;
    }
    if (arg3 == -1) {
        arg3 = strlen(arg2);
    }

    sprintf(buffer, lbl_8048F634, arg3);

    ret = fn_8036A680(arg0, arg1, buffer);
    if (ret != 0) {
        return ret;
    }

    ret = fn_8036A594(arg0, arg1, arg2, arg3);
    if (ret != 0) {
        return ret;
    }

    ret = fn_8036A4E8(arg0, arg1, 0);
    if (ret != 0) {
        return ret;
    }

    arg1->time = fn_8035D258(0) + 300;
    return 0;
}
