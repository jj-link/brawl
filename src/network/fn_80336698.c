#include <string.h>
#pragma force_active on
typedef struct { int field0; int type; char info[256]; char name[256]; } Record;
extern int fn_80337AF0(int, Record *);
extern int fn_803363D4(const char *, char *, const char *, char);
extern long fn_803FC570(const char *, char **, int);
extern char lbl_8059F078[4];
extern char lbl_8059F07C[4];
unsigned char fn_80336698(int arg0, char *arg1, char *arg2, char *arg3) {
    Record rec;
    char buf[8];
    if (fn_80337AF0(arg0, &rec)) {
        if (rec.type == 6) {
            if (arg1) {
                if (fn_803363D4(lbl_8059F078, buf, rec.info, 0x2f) > 0)
                    *arg1 = fn_803FC570(buf, 0, 10);
                else *arg1 = 0;
            }
            if (arg2) {
                if (fn_803363D4(lbl_8059F07C, buf, rec.info, 0x2f) > 0)
                    *arg2 = fn_803FC570(buf, 0, 10);
                else *arg2 = 0;
            }
        } else {
            if (arg1) *arg1 = 0;
            if (arg2) *arg2 = 0;
        }
        if (arg3) strcpy(arg3, rec.name);
        return rec.type;
    }
    if (arg1) *arg1 = 0;
    if (arg2) *arg2 = 0;
    return 0;
}