#pragma force_active on
extern char* strstr(const char* s, const char* sub);
extern unsigned long strlen(const char* s);
extern int sscanf(const char* s, const char* fmt, ...);
extern char lbl_80490E3C[];
extern char lbl_8059FBD8;

int fn_8038D64C(const char* s, int* out) {
    const char* key = lbl_80490E3C;
    char* found = strstr(s, key);
    int local;
    int flag;
    int v;
    if ((found != 0) && (sscanf(found + strlen(key), &lbl_8059FBD8, &local) == 1)) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag == 0) {
        return 0;
    }
    v = local;
    if (v >= 6) {
        v = 6;
    }
    *out = v;
    return 1;
}
