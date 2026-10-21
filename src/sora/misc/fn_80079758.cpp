#pragma force_active on
struct sndSystem;
typedef int s32;
enum SndID { SND_ID_NONE = 0 };
extern sndSystem* g_sndSystem;

struct snd3DGenerator {
    int m_handle;
    s32 prepareSE(SndID id, long param);
};

extern "C" s32 fn_80075830(sndSystem*, SndID, s32, long, s32);
extern "C" s32 fn_800754E8(sndSystem*, SndID, long, s32);

s32 snd3DGenerator::prepareSE(SndID id, long param)
{
    int h = m_handle;
    sndSystem* sys = g_sndSystem;
    if (h != 0) {
        return fn_80075830(sys, id, h, param, -1);
    }
    return fn_800754E8(sys, id, param, -1);
}
