#include <revolution/OS/OSError.h>
#pragma force_active on

extern "C" {
unsigned int strlen(const char*);
char* strncpy(char*, const char*, int);
void OSReport(const char*, ...);
int fn_8001B7F8(const char*);
int fn_8001B8E0(int, int);
int fn_8020DA08(int*, int*);
int fn_803EBF9C(int, void*);
int fn_803EBE4C(void);
int fn_803C3FD0(signed char*);
int fn_803C3F44(void);
int fn_8001B9E8(void);
extern char lbl_80420FC0[];
extern unsigned char lbl_8059C5B4;
extern unsigned char lbl_8059C5B5;
}

struct Flags {
    unsigned r : 8;
    unsigned x : 8;
    unsigned y : 16;
};

struct S {
    const char* p;
    int a, b, c, d;
    Flags flags;
};

struct B {
    unsigned char pad[0x15];
    unsigned char x : 8;
};

extern "C" int fn_8001EE94(S* self) {
    int out2;
    int out1;
    int data[4];
    S local;
    char text[128];
    char* base = lbl_80420FC0;
    int type = fn_8001B7F8(self->p);
    const char* s = self->p;
    unsigned int n = strlen(s);
    const char* q = s;
    for (unsigned int i = 0; i < n; i++) {
        if (*q == ':') {
            strncpy(text, q + 1, 128);
            goto copied;
        }
        q++;
    }
    strncpy(text, s, 128);
copied:
    local.flags = self->flags;
    int result = self->b;
    int status = 5;
    switch (type) {
    case 1:
        break;
    case 2: {
        status = 0x10;
        int rv = fn_8020DA08(&out1, &out2);
        if (rv != 0) {
            fn_8001B8E0(rv, 0);
            OSReport(base + 0x4F8);
        } else {
            status = 0;
            result = out1;
            ((B*)&local)->x = out2;
        }
        break;
    }
    case 3: {
        status = 0x10;
        if (fn_803EBF9C(0x41, data) != 0) {
            fn_803EBE4C();
            OSReport(base + 0x510);
        } else {
            status = 0;
            result = (unsigned)(data[1] * data[3] * data[2]) >> 17;
        }
        break;
    }
    case 4: {
        signed char bytes[2];
        status = 0x10;
        int delta = (unsigned char)self->p[2] - '0';
        ((B*)&local)->x = delta;
        bytes[0] = lbl_8059C5B4 + ((B*)&local)->x;
        bytes[1] = lbl_8059C5B5;
        int rv = fn_803C3FD0(bytes);
        if (rv < 0) {
            fn_803C3F44();
            fn_8001B9E8();
            OSReport(base + 0x528);
        } else {
            status = 0;
            result = rv / 131072;
        }
        break;
    }
    }
    self->flags.r = status;
    self->b = result;
    ((B*)self)->x = ((B*)&local)->x;
    return status;
}
