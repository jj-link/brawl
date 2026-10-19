#pragma force_active on
extern "C" {
extern void* g_ftManager;
void fn_27_10B050(void*, void*);
void fn_27_10B024(void*, void*);

void fn_105_AF88(void* self)
{
    void* arg = self;
    if (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(self) + 0x20000 - 0x1b4) == 1) {
        fn_27_10B050(g_ftManager, *reinterpret_cast<void**>(reinterpret_cast<char*>(arg) + 0x10c));
    } else {
        fn_27_10B024(g_ftManager, *reinterpret_cast<void**>(reinterpret_cast<char*>(arg) + 0x10c));
    }
}
}
