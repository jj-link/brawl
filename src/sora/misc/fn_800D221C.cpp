#pragma force_active on

typedef unsigned char u8;

struct FriendData {
    char pad[0x577];
    u8 state;
};

class ntFriendInfo {
public:
    FriendData* data;
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
extern char lbl_8045726C[];
extern int lbl_805A03A8;

extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_800C8F68(const char*, ...);
extern "C" int fn_800C8524();
extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();
extern "C" void fn_800D0AE0(void*);
extern "C" void fn_80145B98(int, int);

struct Flags {
    u8 rest : 7;
    u8 flag : 1;
};

struct Entry {
    char pad[0x7c];
    unsigned int state : 5;
    unsigned int rest : 27;
    char tail[0x198];
};

struct Parent {
    char pad[0x70];
    Entry entries[5];
};

extern "C" void fn_800D221C(void* self, int state) {
    ntFriendInfo* info = ntFriendInfo::getInstance();
    info->data->state = state;
    g_Network.data->flag = 1;
    netReport__FPCce(lbl_8045726C, state);
    fn_800C8F68(lbl_8045726C, state);

    if (fn_800C8524() != 0) {
        u8 index = fn_800C8548();
        Entry* entry;

        if (index == 0xff)
            entry = 0;
        else
            entry = &((Parent*)self)->entries[index];

        if (entry != 0) {
            entry->state = state;

            u8 local = fn_800C851C();
            if (local == 0xff)
                local = 4;

            ((Flags*)((char*)self + local * 0x218 + 0xc6))->flag = 0;
            fn_800D0AE0(self);
            fn_80145B98(lbl_805A03A8, 0xfe);
        }
    }
}
