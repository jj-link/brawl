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

struct NtReport { char pad[0x18]; };
extern "C" {
extern NtReport s_ReportMutex__8NtReport;
void OSLockMutex(NtReport*);
void OSUnlockMutex(NtReport*);
void fn_801D868C(const char*, va_list);
void fn_800C8F68(const char* fmt, ...) {
    va_list args;
    OSLockMutex(&s_ReportMutex__8NtReport);
    va_start(args, fmt);
    fn_801D868C(fmt, args);
    OSUnlockMutex(&s_ReportMutex__8NtReport);
}
}
