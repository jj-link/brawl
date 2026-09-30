// Runtime.PPCEABI.H/fn_803F86E4.c
// MSL fprintf with CodeWarrior PPC EABI variadic argument layout.

typedef unsigned char u8;

typedef struct {
    char gpr;
    char fpr;
    char reserved[2];
    char* input_arg_area;
    char* reg_save_area;
} __va_list[1];
typedef __va_list va_list;

extern void __builtin_va_info(void*);

#define va_start(ap, fmt) ((void) fmt, __builtin_va_info(&ap))
#define va_end(ap) (void) 0

struct FILE {
    u8 pad[0x50];
};

extern struct FILE __files[];

extern int fwide(struct FILE*, int);
extern void* __FileWrite(void*, const char*, int);
extern int __pformatter_803F7CFC(void* (*)(void*, const char*, int), void*,
                                 const char*, va_list);

int fn_803F86E4(struct FILE* stream, const char* format, ...) {
    va_list args;
    int result;

    if (fwide(stream, -1) >= 0) {
        return -1;
    }
    va_start(args, format);
    result = __pformatter_803F7CFC(__FileWrite, stream, format, args);
    va_end(args);
    return result;
}
