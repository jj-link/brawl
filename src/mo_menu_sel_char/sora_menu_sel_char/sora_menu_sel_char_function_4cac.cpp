#include <types.h>
#pragma force_active on

class muWifiInterfaceTask;
extern muWifiInterfaceTask* g_muWifiInterfaceTask;

extern "C" {
void* memset(void* dst, int c, unsigned long n);
int fn_803F6150(const void* lhs, const void* rhs, unsigned long n);
void fn_800D81C4(muWifiInterfaceTask* task, void* data, u32 size);
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

extern "C" void fn_10_4CAC(SelCharState* self, s32 param4, u32 param5) {
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

    if (param4 == 0) {
        if (fn_803F6150(&buf, self->m_637, 4) == 0) {
            return;
        }
    }
    fn_800D81C4(g_muWifiInterfaceTask, &buf, param5);
    self->m_637[0] = buf.bytes[0];
    self->m_637[1] = buf.bytes[1];
    self->m_637[2] = buf.bytes[2];
    self->m_637[3] = buf.bytes[3];
}
