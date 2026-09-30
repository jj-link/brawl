// Runtime.PPCEABI.H/fn_803F88A4.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803F88A4.s
// (MSL `vsprintf`-style terminator variant: unbounded output into s). Behavior
// recovered from the target disassembly and its in-game caller (r3=s, r4=format,
// r5=va_list): run __pformatter over a __OutStrCtrl{CharStr=s, MaxCharCount=-1,
// CharsWritten=0}, then NUL-terminate at s[end] (the unsigned bound is the -1
// sentinel held in r30, so the s[max-1] arm is unreachable in practice).
// __StringWrite itself lives in auto_StringWrite_text.o and is only referenced
// here, matching the original object (which has no local copy of it).

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

int fn_803F88A4(char* s, const char* format, va_list arg) {
    int end;
    struct __OutStrCtrl osc;
    size_t max;

    max = (size_t) -1;
    osc.CharStr = s;
    osc.MaxCharCount = max;
    osc.CharsWritten = 0;

    end = __pformatter_803F7CFC(__StringWrite, &osc, format, arg);
    if (s != 0) {
        if ((size_t) end < max) {
            s[end] = '\0';
        } else {
            s[max - 1] = '\0';
        }
    }
    return end;
}
