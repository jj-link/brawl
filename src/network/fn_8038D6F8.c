#pragma force_active on
extern char* strstr(const char* s, const char* sub);
extern unsigned long strlen(const char* s);
extern int sscanf(const char* s, const char* fmt, ...);
extern char lbl_80490E50[];
extern char lbl_8059FBD8;

int fn_8038D6F8(const char* s, void* out) {
    const char* key = lbl_80490E50;
    char* found = strstr(s, key);
    if (found != 0) {
        if (sscanf(found + strlen(key), &lbl_8059FBD8, out) == 1) {
            return 1;
        }
    }
    return 0;
}
