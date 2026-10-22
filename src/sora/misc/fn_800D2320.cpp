#pragma force_active on
typedef unsigned char u8;
extern "C" void* memset(void*, int, unsigned long);
extern "C" u8 fn_800C851C();
extern "C" void fn_8014CB1C(void*, int);

class ntFriendInfo {
public:
    u8* data;
    static ntFriendInfo* getInstance();
};
struct NetworkData {
    char pad[0x33f4];
    u8 flag;
};
struct Network {
    char pad[0x30];
    NetworkData* data;
};
extern Network g_Network;
struct Entry { u8 name[10]; char pad[0x20e]; };
struct Parent { char pad[0x250]; Entry entries[5]; };

extern "C" void fn_800D2320(void* self, const u8* name) {
    int count;
    u8* p;
    u8* dst = ntFriendInfo::getInstance()->data + 0x4f0;
    p = (u8*)name;
    count = 5;
    memset(dst, 0, 10);
    while (--count >= 0) {
        int value = (dst[0] = p[0]) | (dst[1] = p[1]);
        p += 2;
        dst += 2;
        if (value == 0)
            break;
    }
    u8 index = fn_800C851C();
    if (index == 0xff)
        index = 4;
    count = 5;
    p = ((Parent*)self)->entries[index].name;
    memset(p, 0, 10);
    while (--count >= 0) {
        int value = (p[0] = name[0]) | (p[1] = name[1]);
        name += 2;
        p += 2;
        if (value == 0)
            break;
    }
    g_Network.data->flag = 1;
    fn_8014CB1C(ntFriendInfo::getInstance(), 1);
}
