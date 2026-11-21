#include <types.h>
#include <mv/mv_THPPlayer.h>
#include <mv/mv_THPAudioDecode.h>

#pragma force_active on

#define buffer (*(AudioDecMessage**)((char*)&g_thpObject + 0xEC))

extern "C" u32 fn_8007D9F8(s16* out, s16* left, u32 requested, s32* status) {
    u32 result = (u32)&g_thpObject;

    if (*(AudioDecMessage**)(result + 0xEC) == 0) {
        AudioDecMessage* popped = (AudioDecMessage*)PopDecodedAudioBuffer(0);
        *(AudioDecMessage**)(result + 0xEC) = popped;
        if (popped == 0) {
            *status = 2;
            return 0;
        }
    }

    u32 current = (u32)&g_thpObject;
    if ((*(AudioDecMessage**)(current + 0xEC))->unk8 != 0) {
        u32 count = (*(AudioDecMessage**)(current + 0xEC))->unk8;
        if (count >= requested)
            count = requested;

        s16* src = (s16*)(*(AudioDecMessage**)(current + 0xEC))->unk4;
        result = count;

        if (left == 0) {
            for (u32 i = 0; i < count; i++) {
                *out++ = src[1];
                src += 2;
            }
        } else {
            for (u32 i = 0; i < count; i++) {
                *left++ = src[0];
                *out++ = src[1];
                src += 2;
            }
        }

        buffer->unk8 -= result;
        buffer->unk4 = (u32)src;
        if (buffer->unk8 == 0) {
            PushFreeAudioBuffer(buffer);
            buffer = 0;
            *status = 1;
        } else {
            *status = 0;
        }
    }

    return result;
}