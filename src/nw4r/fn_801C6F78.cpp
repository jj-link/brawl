#include <string.h>
#pragma force_active on

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual int fn_800480DC(int, int, unsigned int, unsigned int);
    virtual int fn_801AB1C4(int, int, const char*, unsigned int, unsigned int);
    void* resource;
    char directory[256];
};

struct Entry {
    unsigned int value;
    const char* path;
    unsigned int unused[2];
    unsigned int a;
    unsigned int b;
};
extern "C" int fn_801C78A0(void*, unsigned int, Entry*);

extern "C" int fn_801C6F78(Class_8042B6D0* self, unsigned int index, int arg2, int arg3) {
    Entry entry;
    char buffer[256];
    if (fn_801C78A0(self->resource, index, &entry) == 0) return 0;
    unsigned int a;
    unsigned int b;
    const char* path = entry.path;
    if (path != 0) {
        b = entry.b;
        a = entry.a;
        const char* resolvedPath;
        if (*path == '/') {
            resolvedPath = path;
        } else {
            size_t pathLength = strlen(path);
            size_t directoryLength = strlen(self->directory);
            if (pathLength + directoryLength >= 256) return 0;
            strncpy(buffer, self->directory, directoryLength + 1);
            strncat(buffer, path, pathLength + 1);
            resolvedPath = buffer;
        }
        return self->fn_801AB1C4(arg2, arg3, resolvedPath, a, b);
    }
    return self->fn_800480DC(arg2, arg3, entry.a, entry.b);
}
