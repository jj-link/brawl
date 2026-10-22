#pragma force_active on

extern "C" int strlen(const char*);
extern "C" int fn_8018CE5C(const int* a, const char* b, int c);

extern "C" int fn_8018D014(const int* arg0, const char* arg1) {
    if (*arg0 != 0) {
        if (arg1 != 0) {
            int tmp = fn_8018CE5C(arg0, arg1, (int)strlen(arg1));
            if (tmp != 0) {
                return (tmp - (*arg0 + 0x18)) / 16;
            }
        }
    }
    return -1;
}
