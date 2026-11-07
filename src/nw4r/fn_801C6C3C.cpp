#include <string.h>
#pragma force_active on

class Class_8042B6D0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int, int, unsigned int, unsigned int);
    virtual int slot5(int, int, const char*, unsigned int, unsigned int);
    void* resource;
    char directory[256];
};

struct Info0 {
    unsigned int a;
    unsigned int b;
    const char* path;
    unsigned int c;
};
struct Info1 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d[3];
};
struct Info2 {
    unsigned int a;
    const char* path;
    unsigned int b;
    unsigned int d[3];
};

extern "C" int fn_801C7CA8(void*, unsigned int, Info0*);
extern "C" int fn_801C7DA8(void*, unsigned int, unsigned int, unsigned int*);
extern "C" int fn_801C78A0(void*, unsigned int, Info2*);
extern "C" int fn_801C79B0(void*, unsigned int, unsigned int, Info1*);

extern "C" int fn_801C6C3C(Class_8042B6D0* self, unsigned int id, int arg2, int arg3) {
    unsigned int out[2];
    Info0 info0;
    Info2 info2;
    Info1 info1;
    char buffer[256];
    char buffer2[256];
    const char* resolved;
    if (fn_801C7CA8(self->resource, id, &info0) == 0) return 0;
    const char* path = info0.path;
    if (path != 0) {
        if (*path == '/') {
            resolved = path;
        } else {
            size_t pathLength = strlen(path);
            size_t directoryLength = strlen(self->directory);
            if (pathLength + directoryLength >= 256) return 0;
            strncpy(buffer, self->directory, directoryLength + 1);
            strncat(buffer, path, pathLength + 1);
            resolved = buffer;
        }
        return self->slot5(arg2, arg3, resolved, 0, 0);
    }
    if (fn_801C7DA8(self->resource, id, 0, out) == 0) return 0;
    if (fn_801C78A0(self->resource, out[0], &info2) == 0) return 0;
    if (fn_801C79B0(self->resource, out[0], out[1], &info1) == 0) return 0;
    path = info2.path;
    unsigned int off = info2.b + info1.b;
    id = info1.c;
    if (path != 0) {
        if (*path == '/') {
            resolved = path;
        } else {
            size_t pathLength = strlen(path);
            size_t directoryLength = strlen(self->directory);
            if (pathLength + directoryLength >= 256) return 0;
            strncpy(buffer2, self->directory, directoryLength + 1);
            strncat(buffer2, path, pathLength + 1);
            resolved = buffer2;
        }
        return self->slot5(arg2, arg3, resolved, off, id);
    }
    return self->slot4(arg2, arg3, off, id);
}
