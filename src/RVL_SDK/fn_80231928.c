#pragma force_active on
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

extern char lbl_80527FC0[];
extern char lbl_8059EDD8;
extern int fn_803F88A4(char*, const char*, va_list);
extern int sprintf(char*, const char*, ...);
extern void OSReport(const char*, ...);

void fn_80231928(int a, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fn_803F88A4(lbl_80527FC0, fmt, ap);
    sprintf(lbl_80527FC0, &lbl_8059EDD8, lbl_80527FC0);
    OSReport(lbl_80527FC0);
}
