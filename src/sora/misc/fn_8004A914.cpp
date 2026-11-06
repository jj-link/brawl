#include <ip/ip_network_producer.h>
#pragma force_active on

extern "C" void fn_800237A0(void* p, int flag);
extern "C" void* g_gfFileIOManager;

struct Unk8004A914 {
    int m_0;
    ipNetworkProducer* m_4;
    char pad[0x24 - 0x8];
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 3;
    u8 m_25;
};

extern "C" void fn_8004A914(Unk8004A914* self, int mode) {
    self->m_0 = mode;
    self->b4 = 0;
    self->m_25 = 0xFF;
    if (self->m_4 != NULL) {
        self->m_4->clear();
    }
    fn_800237A0(g_gfFileIOManager, mode == 1);
}
