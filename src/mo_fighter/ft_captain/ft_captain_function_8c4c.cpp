#pragma force_active on
struct ftCommonData {
    unsigned char padding[0x88];
    void* data;
};

extern "C" void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);

extern "C" {
    extern unsigned char g_ftCommonDataAccesser;
}

extern "C" void* fn_100_8C4C() {
    return static_cast<ftCommonData*>(
        getData__20ftCommonDataAccesserCF6ftKind(
            &g_ftCommonDataAccesser, 9))->data;
}
