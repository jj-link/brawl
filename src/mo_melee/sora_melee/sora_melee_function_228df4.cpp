#pragma force_active on
#include <types.h>
#include <nw4r/g3d/g3d_resmat.h>
extern "C" void* fn_8018F2EC(s32*, u8, void*);
extern "C" u32 fn_801926CC(void**);
struct Slot { u8 flags; u8 a; u8 b; u8 c; u8 d; void* data; };
extern "C" s32 fn_27_228DF4(void* arg0, void* arg1)
{
            u8 flags;
    u8* a1 = (u8*)arg1;
    u8* base = (u8*)arg0;
    s32 result = 0;
    u8 flag = 0;
    Slot* r28 = 0;
    if ((a1[0] >> 7) & 1) flag = 1;
    s32 p = *(s32*)(a1 + 8);
    s32 q = *(s32*)(p + 0x44);
    s32 r = *(s32*)(q + a1[1] * 4);
    s32 resource = *(s32*)(r + 0xE8);
    void* matResult = fn_8018F2EC(&resource, a1[2], (void*)r);
    u8* matPtr = (u8*)matResult;
    s32 offset30 = *(s32*)(matPtr + 0x30);
    void* spC;
    if (offset30 != 0) spC = (void*)(matPtr + offset30);
    else spC = 0;
    u32 id = fn_801926CC(&spC);
    nw4r::g3d::ResTexObj tex(matPtr + 0x3c);
    void* texResult = tex.GetTexObj((GXTexMapID)a1[3]);
    s32 idx = 0;
    Slot* ptr = (Slot*)(base + 0x9c);
    for (s32 i = 0; i < 36; i++) {
        if (!((ptr->flags >> 6) & 1)) {
            result = 1;
            flags = a1[0];
            ptr->flags = flags;
            ptr->a = a1[1];
            ptr->b = a1[2];
            ptr->c = a1[3];
            ptr->d = a1[4];
            ptr->data = *(void**)(a1 + 8);
            ptr->flags = flags | 0x40;
            r28 = (Slot*)(base + 0x9c) + idx;
            break;
        } else {
            ptr++;
            idx++;
        }
    }
    if (result != 0) {
        u8* ptr2 = base + 0x24c;
        s32 found = 0;
        for (s32 i = 0; i < 4; i++) {
            if (ptr2[0] != 0 && *(u32*)(ptr2 + 4) == id) {
                found = 1;
                ptr2[0xd] += flag;
                ptr2[0xc] += 1;
                r28->d = (u8)i;
                break;
            }
            ptr2 += 16;
        }
        if (found == 0) {
            u8* ptr3 = base + 0x24c;
            for (s32 i = 0; i < 4; i++) {
                if (ptr3[0] == 0) {
                    ptr3[0] = 1;
                    ptr3[0xc] = 1;
                    ptr3[0xd] = flag;
                    r28->d = (u8)i;
                    *(u32*)(ptr3 + 4) = id;
                    *(s32*)(ptr3 + 8) = (s32)texResult;
                    break;
                }
                ptr3 += 16;
            }
        }
    }
    return result;
}
