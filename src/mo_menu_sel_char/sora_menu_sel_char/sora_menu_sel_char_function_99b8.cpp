#pragma force_active on
struct muWifiInterfaceTask {
    unsigned char pad[0xFCA];
    unsigned char flags;
};

static inline unsigned char normalize(unsigned char value) {
    if (value == 0xFF) {
        value = 4;
    }
    return value;
}

extern "C" {
extern muWifiInterfaceTask* g_muWifiInterfaceTask;

unsigned char fn_10_1278();
unsigned char fn_800D4544(muWifiInterfaceTask*);

bool fn_10_99B8() {
    unsigned char value;
    muWifiInterfaceTask* task = g_muWifiInterfaceTask;
    bool result = (task->flags >> 5) & 1;
    if (!result) {
        value = normalize(fn_10_1278());
        unsigned char current = fn_800D4544(task);
        result = current == value;
    }
    return result;
}
}
