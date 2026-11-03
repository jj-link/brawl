#pragma force_active on
typedef signed int s32;

typedef struct ErrorMap {
    s32 entries[82];
} ErrorMap;

extern const ErrorMap lbl_8040D460;
extern char lbl_8047C0C0[];

extern void fn_8020CAE8(s32 result);
extern void fn_8020DB70(s32 flag, char* msg, ...);
extern void OSReport(const char* msg, ...);
extern int sprintf(char* s, const char* fmt, ...);

s32 fn_8020CAEC(s32 result) {
    ErrorMap errorMap;
    char* str;
    char buf1[128];
    char buf2[128] __attribute__((aligned(64)));
    int i;

    str = lbl_8047C0C0;
    errorMap = lbl_8040D460;
    i = 0;
    if (result >= 0) {
        return result;
    }

    for (; i < 82; i += 2) {
        if (result == errorMap.entries[i]) {
            if (result == -114 || result == -116 || result == -117 || result == -9 || result == -12) {
                sprintf(buf1, str + 200, result);
                fn_8020DB70(0, buf1);
            }
            fn_8020CAE8(result);
            return errorMap.entries[i + 1];
        }
    }

    OSReport(str + 220, result);
    sprintf(buf2, str + 272, result);
    fn_8020DB70(0, buf2);
    fn_8020CAE8(result);
    return -64;
}
