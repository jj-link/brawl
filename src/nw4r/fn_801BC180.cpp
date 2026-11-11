#include <types.h>
#include <nw4r/snd/snd_Util.h>
#pragma force_active on
extern "C" void* fn_801D3698(u8, u32, void*);
extern "C" const void* fn_801BC180(void* arg0, const nw4r::snd::detail::Util::DataRef<void>& arg1, s32 arg2) {
    u8 type = arg1.dataType;
    const void* result = 0;
    switch (type) {
    case 0: break;
    case 1: result = &arg1; break;
    case 2: {
        u8* data = (u8*)fn_801D3698(arg1.refType, arg1.value, (void*)(*(s32*)((u8*)arg0 + 4) + 8));
        if (!data) return 0;
        s32 i = 0;
        while (arg2 > (s32)data[i + 1]) {
            i++;
            if (i >= (s32)data[0]) return 0;
        }
        result = (void*)(data + i * 8 + (((s32)data[0] + 4) & ~3));
        break;
    }
    case 3: {
        u8* data = (u8*)fn_801D3698(arg1.refType, arg1.value, (void*)(*(s32*)((u8*)arg0 + 4) + 8));
        if (!data) return 0;
        if (arg2 < (s32)data[0] || arg2 > (s32)data[1]) return 0;
        data += (arg2 - (s32)data[0]) * 8;
        result = data + 4;
        break;
    }
    }
    return result;
}
