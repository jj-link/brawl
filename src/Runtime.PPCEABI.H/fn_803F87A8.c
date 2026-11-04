#pragma force_active on
// Runtime.PPCEABI.H/vprintf.c
// MSL vprintf with CodeWarrior PPC EABI variadic argument layout.

typedef unsigned char u8;

typedef struct {
    char gpr;
    char fpr;
    char reserved[2];
    char* input_arg_area;
    char* reg_save_area;
} __va_list[1];
typedef __va_list va_list;

struct FILE {
    u8 pad[0x50];
};

extern struct FILE __files[];

extern int fwide(struct FILE*, int);
extern void* __FileWrite(void*, const char*, int);
extern int __pformatter_803F7CFC(void* (*)(void*, const char*, int), void*,
                                 const char*, va_list);

int vprintf(const char* format, va_list args) {
    int result;

    if (fwide(&__files[1], -1) >= 0) {
        return -1;
    }
    result = __pformatter_803F7CFC(__FileWrite, &__files[1], format, args);
    return result;
}
