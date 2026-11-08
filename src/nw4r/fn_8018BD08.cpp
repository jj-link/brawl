#pragma force_active on
extern "C" {
extern char lbl_8059E8D8;
extern char lbl_8059E8DC;
int fn_80210F44(void*, const char*, void*);
int fn_80210EEC(void*, const char*);
int fn_80210FC0(void*, void*);
int fn_80211078(void*);
int stricmp(const char*, const char*);
int fn_8018BD08(void* arg0, const char* arg1) {
    int iter[4];
    int entry[4];
    int result = -1;
    fn_80210F44(arg0, &lbl_8059E8D8, iter);
    while (fn_80210FC0(iter, entry)) {
        if (entry[2]) {
            fn_80210EEC(arg0, (const char*)entry[3]);
            result = fn_8018BD08(arg0, arg1);
            fn_80210EEC(arg0, &lbl_8059E8DC);
            if (result != -1) break;
        } else if (stricmp(arg1, (const char*)entry[3]) == 0) {
            result = entry[1];
            break;
        }
    }
    fn_80211078(iter);
    return result;
}
}