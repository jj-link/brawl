#pragma force_active on
typedef unsigned char u8;

extern "C" int fn_800B61C0(void*);
extern "C" void fn_16_AF8(void*);
extern "C" void fn_80147434();

struct muWifiInterfaceTask_t {
    u8 pad[0xfca];
    u8 m_flags;
};

extern muWifiInterfaceTask_t* g_muWifiInterfaceTask;

struct SelfMenuMain {
    u8 pad_00[0x44];
    void* m_res44;
    u8 pad_48[0x138 - 0x48];
    int m_val138;
    u8 pad_13c[0x14c - 0x13c];
    u8 m_sub14c[0x1];
};

extern "C" int fn_2_39D48(SelfMenuMain* self) {
    if (fn_800B61C0(self->m_res44)) {
        return self->m_val138;
    }
    fn_16_AF8(&self->m_sub14c);
    g_muWifiInterfaceTask->m_flags &= ~0x10;
    fn_80147434();
    return 10;
}
