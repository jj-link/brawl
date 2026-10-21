#pragma force_active on
typedef unsigned char u8;
typedef wchar_t u16;
typedef unsigned long long u64;

class Message {
public:
    static void utf8to16(u16*, const char*);
};

extern "C" {
struct muWifiInterfaceTask;
extern muWifiInterfaceTask* g_muWifiInterfaceTask;

void fn_800D2320(muWifiInterfaceTask*, const u16*);
void fn_800D24CC(muWifiInterfaceTask*, unsigned int);
void fn_800D2BC8(muWifiInterfaceTask*, u64);
void fn_800343CC(void*, u64, void*);
void fn_800D2520(muWifiInterfaceTask*, const void*);
void fn_800D2AD0(muWifiInterfaceTask*, const u16*, int);
void fn_800D2428(muWifiInterfaceTask*, const u16*);

void fn_14_A18(u8* self) {
    u8 info[84];
    u16 finalText[22];
    u16 entries[22];
    u16 name[6];
    unsigned int selection;
    u64 id;
    const char* entry;
    muWifiInterfaceTask* task = g_muWifiInterfaceTask;

    Message::utf8to16(name, (const char*)self + 0x2310);
    fn_800D2320(task, name);

    selection = self[0x2300];
    fn_800D24CC(task, selection);
    if (selection == 0xFF) {
        id = *(u64*)(self + 0x2308);
        fn_800D2BC8(task, id);
        fn_800343CC(*(void**)(self + 0x2A2C), id, info);
        fn_800D2520(task, info);
    }

    entry = (const char*)self + 0x2325;
    for (selection = 0; (int)selection < 4; ++selection, entry += 0x51) {
        Message::utf8to16(entries, entry);
        fn_800D2AD0(task, entries, selection);
    }

    Message::utf8to16(finalText, (const char*)self + 0x2469);
    fn_800D2428(task, finalText);
}
}
