#pragma force_active on
typedef unsigned long size_t;
typedef struct { int __x[1]; } __va_list;
typedef __va_list va_list[1];

struct __OutStrCtrl {
    char* CharStr;
    size_t MaxCharCount;
    size_t CharsWritten;
};

extern void* __StringWrite(void* pCtrl, const char* pBuffer, size_t char_num);
extern int __pformatter_803F7CFC(void* (*WriteProc)(void*, const char*, size_t),
                                 void* WriteProcArg, const char* format,
                                 va_list arg);

int vsnprintf(char* s, int count, const char* format, va_list arg) {
    int end;
    struct __OutStrCtrl osc;

    osc.CharStr = s;
    osc.MaxCharCount = (size_t)count;
    osc.CharsWritten = 0;

    end = __pformatter_803F7CFC(__StringWrite, &osc, format, arg);
    if (s != 0) {
        if ((unsigned)end < (unsigned)count) {
            s[end] = '\0';
        } else if (count != 0) {
            *(s + count - 1) = '\0';
        }
    }
    return end;
}
