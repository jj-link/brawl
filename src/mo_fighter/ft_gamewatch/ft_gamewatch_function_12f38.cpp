#pragma force_active on
extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
extern const float lbl_107_rodata_88;

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void fn_27_1652A8(void*, float, unsigned long, unsigned long, float,
                  unsigned long, unsigned long);
void fn_107_130DC(void*, void*);
void fn_107_141A0(void*, void*);
}

static inline void setup(void* accesser, void* common) {
    const char* data = *reinterpret_cast<const char**>(
        static_cast<char*>(common) + 0xb8);

    fn_27_1652A8(accesser, *reinterpret_cast<const float*>(data + 0x1c),
                  0x1f7, 0x21000005, lbl_107_rodata_88, 0x21000007, 0);
}

extern "C" void fn_107_12F38(void* owner, void* accesser) {
    setup(accesser, getData__20ftCommonDataAccesserCF6ftKind(
        g_ftCommonDataAccesser, 0x12));
    fn_107_130DC(owner, accesser);
    fn_107_141A0(owner, accesser);
}
