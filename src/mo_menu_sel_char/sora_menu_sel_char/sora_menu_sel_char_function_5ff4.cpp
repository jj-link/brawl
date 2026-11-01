#include <gm/gm_global.h>
#pragma force_active on

struct muWifiInterfaceTask {
    unsigned char pad[0xFCA];
    unsigned char flags;
};
extern "C" muWifiInterfaceTask* g_muWifiInterfaceTask;

extern "C" {
void* memset(void* dst, int c, unsigned long n);
int fn_803F6150(const void* lhs, const void* rhs, unsigned long n);
void fn_800D81C4(void* task, void* data, u32 size);
u8 fn_10_1278(void);
u8 fn_800D4544(void* task);
}

struct SelCharBits {
    u8 a : 2;
    u8 b : 2;
    u8 c : 2;
    u8 pad0 : 2;
    u8 d : 3;
    u8 e : 1;
    u8 pad1 : 4;
};

struct SelCharState {
    char pad000[0x5c8];
    u8 m_5c8;
    char pad5c9[3];
    u32 m_5cc;
    char pad5d0[4];
    u32 m_5d4;
    u32 m_5d8;
    u32 m_5dc;
    char pad5e0[0x20];
    u32 m_600;
    u32 m_604;
    char pad608[0x2f];
    u8 m_637[4];
};

extern "C" void fn_10_5FF4(SelCharState* self, s32 arg1) {
    unsigned char value;
    self->m_5dc = (u32)arg1;
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int result;
    if (state >= 0 && state < 4) result = 1; else result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc) result = 1; else result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r0_4;
            if (state >= 0xc && state < 0x10) r0_4 = 1; else r0_4 = 0;
            result = 3;
            if (r0_4 != 0) result = 2;
        }
    }
    if (result == 2) {
        void* task = g_muWifiInterfaceTask;
        bool ind = (((unsigned char*)task)[0xFCA] >> 5) & 1;
        if (!ind) {
            value = fn_10_1278();
            if (value == 0xff) value = 4;
            unsigned char current = fn_800D4544(task);
            ind = (current == value);
        }
        if (ind != 0) {
            union {
                SelCharBits bits;
                u8 bytes[4];
            } buf;
            memset(&buf, 0, 4);
            buf.bits.a = self->m_5d4;
            buf.bits.b = self->m_5cc;
            buf.bits.c = (self->m_5c8 != 0);
            buf.bytes[2] = self->m_5d8;
            buf.bytes[3] = self->m_5dc;
            buf.bits.d = self->m_604;
            buf.bits.e = self->m_600;
            if (fn_803F6150(&buf, self->m_637, 4) != 0) {
                fn_800D81C4(g_muWifiInterfaceTask, &buf, 1);
                self->m_637[0] = buf.bytes[0];
                self->m_637[1] = buf.bytes[1];
                self->m_637[2] = buf.bytes[2];
                self->m_637[3] = buf.bytes[3];
            }
        }
    }
}
