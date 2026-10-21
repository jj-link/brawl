#pragma force_active on
typedef int s32;
struct OSAlarm;
struct OSContext;

extern "C" void OSResumeThread(void* thread);
extern "C" void* fn_80146B80();
extern "C" char g_Network[];
extern void* g_gfPadSystem;

class gfPadSystem {
public:
    static void* _alarmCallback(OSAlarm* alarm, OSContext* context);
};

void* gfPadSystem::_alarmCallback(OSAlarm* alarm, OSContext* context) {
    *(s32*)((char*)g_gfPadSystem + 0x30) += 1;
    void* thread = *(void**)((char*)g_gfPadSystem + 0xB54);
    if (thread != 0) {
        OSResumeThread((char*)thread + 8);
    }
    void* ret = (void*)g_Network;
    if (ret != 0) {
        ret = fn_80146B80();
    }
    return ret;
}
