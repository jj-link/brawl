#include <string.h>
#pragma force_active on

struct Info {
    unsigned int value;
    const char* path;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};

class Class_804669F8 {
public:
    virtual void fn_801C3040();
    virtual void fn_801C35BC();
    virtual void fn_801C362C();
    virtual void fn_801C377C();
    virtual int fn_801C10F8(int, int, unsigned int, unsigned int);
    virtual int fn_801C10F0(int, int, const char*, unsigned int, unsigned int);

    void* data;
    char base[256];
};

extern "C" int fn_801C78A0(void*, unsigned int, Info*);

extern "C" int fn_801C6E60(
    Class_804669F8* self, unsigned int index, int a, int b
) {
    Info info;
    char buffer[256];
    unsigned int x;
    unsigned int y;

    if (!fn_801C78A0(self->data, index, &info))
        return 0;

    const char* path = info.path;
    if (path) {
        y = info.b;
        x = info.a;

        const char* resolved;
        if ('/' == *path) {
            resolved = path;
        } else {
            unsigned int len = strlen(path);
            unsigned int baseLen = strlen(self->base);

            if (len + baseLen >= 256)
                return 0;

            strncpy(buffer, self->base, baseLen + 1);
            strncat(buffer, path, len + 1);
            resolved = buffer;
        }
        return self->fn_801C10F0(a, b, resolved, x, y);
    }

    return self->fn_801C10F8(a, b, info.a, info.b);
}
