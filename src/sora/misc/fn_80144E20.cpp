#include <types.h>
#include <nt/nt_send.h>
#include <revolution/OS/OSTime.h>

#pragma force_active on

typedef void (*Callback)(u8, void*, u32, u16);

extern "C" {
extern char lbl_8045E7E8[];
extern void* lbl_805A03A8;
extern int lbl_805A03E8;
extern const float lbl_805A2B50;
extern const float lbl_805A2B54;
extern const float lbl_805A2B58;

void netReport__FPCce(const char*, ...);
void report__8NtReportFPCce(const char*, ...);
void fn_80143C48(void*, int);
void fn_8013FB0C(void);
void fn_801451B0(u8, void*, u32);
void fn_8014608C(void*, u8, u8, void*, u16, u16);
}

static inline void updateTime(float* value, float dt) {
    if (lbl_805A2B50 == *value)
        *value = dt;
    else
        *value = lbl_805A2B54 * *value + lbl_805A2B58 * dt;
}

extern "C" void fn_80144E20(u8 aid, void* data, u32 seq) {
    char* p = (char*)data;
    char* msg = lbl_8045E7E8;

    if ((u8)p[0] != 9)
        return;

    if (aid >= 4) {
        netReport__FPCce(msg + 0x108, aid);
        return;
    }

    char* obj = (char*)lbl_805A03A8 + aid * 0xE50;
    char* e = obj + 0x44;
    if ((u8)obj[0x44] == 0) {
        netReport__FPCce(msg + 0x118, aid);
        return;
    }

    switch ((int)(unsigned char)p[4]) {
    case 1:
        break;
    case 2:
    case 3:
        goto middle;
    default:
        goto general;
    }

    {
        *(u16*)(e + 8) = *(u16*)(p + 8);

        u8 packet[16];
        packet[0] = 9;
        packet[1] = 0xF7;
        *(u16*)(packet + 6) = 0x10;
        packet[4] = 2;
        *(u16*)(packet + 8) = *(u16*)(p + 8);
        *(u32*)(packet + 12) = *(u32*)(p + 12);

        g_NtSend->pushback(aid, packet, 0x10);
        fn_80143C48(lbl_805A03A8, 1);
        fn_8013FB0C();
        return;
    }

middle:
    {
        int i = *(int*)(e + 0x14);
        int n = *(int*)(e + 0x18);
        char* ent = i == n ? 0 : (i = (int)(e + i * 0x38C), (char*)(i + 0x1C));

        if (ent && *(u16*)(p + 8) == *(u16*)(ent + 0xE)) {
            if ((u8)p[4] == 2)
                *(int*)ent = 3;
            else
                *(int*)ent = 4;

            u32 now = OSGetTick();
            u32 sent = *(u32*)(p + 0xC);
            float dt = (float)(now - sent);
            updateTime((float*)(e + 4), dt);
        }
        return;
    }

general:
    if ((u8)p[4] == 6) {
        *(u16*)(e + 8) = *(u16*)(p + 8);
        netReport__FPCce(msg + 0x130, aid, *(u16*)(p + 8));
    }

    if ((s16)(*(u16*)(p + 8) - *(u16*)(e + 8)) <= 0) {
        u32 packet[4];
        u8* bytes = (u8*)packet;
        bytes[0] = 9;
        bytes[1] = 0xF7;
        *(u16*)(bytes + 6) = 0x10;
        bytes[4] = 2;
        *(u16*)(bytes + 8) = *(u16*)(p + 8);
        *(u32*)(bytes + 12) = *(u32*)(p + 12);
        g_NtSend->pushback(aid, packet, 0x10);
        return;
    }

    if (*(int*)((char*)lbl_805A03A8 + 0x398C) == 0) {
        u32 packet[4];
        u8* bytes = (u8*)packet;
        bytes[0] = 9;
        bytes[1] = 0xF7;
        *(u16*)(bytes + 6) = 0x10;
        bytes[4] = 3;
        *(u16*)(bytes + 8) = *(u16*)(p + 8);
        *(u32*)(bytes + 12) = *(u32*)(p + 12);
        g_NtSend->pushback(aid, packet, 0x10);
        return;
    }

    {
        u32 packet[4];
        u8* bytes = (u8*)packet;
        bytes[0] = 9;
        bytes[1] = 0xF7;
        *(u16*)(bytes + 6) = 0x10;
        bytes[4] = 2;
        *(u16*)(bytes + 8) = *(u16*)(p + 8);
        *(u32*)(bytes + 12) = *(u32*)(p + 12);
        g_NtSend->pushback(aid, packet, 0x10);
    }

    *(u16*)(e + 8) = *(u16*)(p + 8);
    netReport__FPCce(msg + 0x14C, aid, (u8)p[4], *(u16*)(p + 8));

    if (lbl_805A03E8)
        return;

    if ((u8)p[4] < 0x1C) {
        fn_801451B0(aid, data, seq);
        return;
    }

    if ((u8)p[4] == 0x1C) {
        Callback cb = *(Callback*)((char*)lbl_805A03A8 + 0x14);
        if (cb) {
            cb(aid, p + 0x10, seq, *(u16*)(p + 8));
            return;
        }

        report__8NtReportFPCce(msg + 0x16C, (u8)p[0]);
        return;
    }

    if ((u8)p[4] > 0x1C)
        fn_8014608C((char*)lbl_805A03A8 + 0x3984, aid, (u8)p[4], data, (u16)seq, *(u16*)(p + 8));
    return;
}
