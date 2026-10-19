#pragma force_active on
extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);

void* fn_98_9540() {
    return *reinterpret_cast<void**>(
        static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 7)) + 0x88);
}
}
