#pragma force_active on
typedef unsigned long size_t;

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

struct __OutStrCtrl {
    char* CharStr;
    size_t MaxCharCount;
    size_t CharsWritten;
};

extern void* __StringWrite(void* pCtrl, const char* pBuffer, size_t char_num);
extern int __pformatter_803F7CFC(void* (*WriteProc)(void*, const char*, size_t),
                                 void* WriteProcArg, const char* format,
                                 va_list arg);

int snprintf(char* s, size_t n, const char* format, ...) {
    va_list args;
    struct __OutStrCtrl osc;
    int end;

    osc.CharStr = s;
    osc.MaxCharCount = n;
    va_start(args, format);
    osc.CharsWritten = 0;
    end = __pformatter_803F7CFC(__StringWrite, &osc, format, args);
    va_end(args);
    if (s != 0) {
        if ((unsigned)end < n) {
            s[end] = '\0';
        } else if (n != 0) {
            s[n - 1] = '\0';
        }
    }
    return end;
}
