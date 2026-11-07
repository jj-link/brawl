#include <snd/snd_system.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_801C6C1C(void* self, int id, s32* out);
extern "C" s32 fn_8007AB34(void* heap, SndGroupID id);
extern "C" s32 fn_8007A324(void* heap, int a, SndGroupID id, s32 size);
extern "C" s32 fn_8007A5EC(void* heap, s32 a, SndGroupID id, s32 size);
extern "C" void fn_80079AA4(void* self, SndGroupID id, s32 a, s32 b);
extern "C" s32 fn_8007A314(void* heap, s32 idx);
extern "C" void fn_801CA274(void* self, SndGroupID id, s32 a, s32 b);
extern "C" void fn_8007A78C(void* heap, SndGroupID id, s32 idx);

int sndSystem::loadSoundGroup(SndGroupID sndGroupId, int arg1, bool isRequest) {
    s32 buf[8];
    s32 size;
    s32 r;

    if (*((u8*)this + 0x6EE) == 0) {
        return -5;
    }
    ::fn_801C6C1C(this, sndGroupId, buf);
    size = buf[3] + buf[5];
    if (size == 0) {
        return -3;
    }
    if (::fn_8007AB34(m_sndHeapSys, sndGroupId) != 0) {
        return -1;
    }
    r = ::fn_8007A324(m_sndHeapSys, arg1, sndGroupId, size);
    if (r == 0x1C) {
        return -2;
    }
    size = ::fn_8007A5EC(m_sndHeapSys, r, sndGroupId, size);
    if (size == -1) {
        return -2;
    }
    if (isRequest) {
        ::fn_80079AA4(*(void**)((u8*)this + 0xB98), sndGroupId, r, size);
    } else {
        ::fn_801CA274((u8*)this + 0x18C, sndGroupId, ::fn_8007A314(m_sndHeapSys, r), 0x10000);
        ::fn_8007A78C(m_sndHeapSys, sndGroupId, r);
    }
    return size;
}
