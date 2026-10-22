#pragma force_active on
extern "C" unsigned long strlen(const char*);
struct Entry { int pad[3]; int offset; };
extern "C" Entry* fn_8018CE5C(const int*, const char*, int);
extern "C" int fn_8018CF30(const int* self, const char* str) {
    if (*self != 0 && str != 0) {
        Entry* entry = fn_8018CE5C(self, str, (int)strlen(str));
        if (entry != 0) return *self + entry->offset;
    }
    return 0;
}
