#pragma force_active on

typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned char u8;

struct FriendData {
    unsigned int data[3];
};

extern "C" {
void fn_80351A08(FriendData*, u64);
int fn_80351C70(FriendData*, FriendData*);
int fn_8035129C(FriendData*);
char* getFriendInfo__12ntFriendInfoFv(void*);
void* getInstance__12ntFriendInfoFv();
}

extern int lbl_805A0434;

extern "C" int fn_801483A4(u64 id) {
    FriendData data;
    FriendData* p;
    FriendData* entry;
    int j;
    int i;

    fn_80351A08(&data, id);
    entry = (FriendData*)(getFriendInfo__12ntFriendInfoFv(getInstance__12ntFriendInfoFv()) + 0x50);
    p = entry;
    for (i = 0; i < 0x40; i++, p++) {
        if (fn_80351C70(p, &data) != 0) {
            break;
        }
    }
    if (i < 0x40) {
        return i;
    }
    for (j = 0; j < 0x40; j++, entry++) {
        if (*((u8*)lbl_805A0434 + j + 0x12) == 0 && fn_8035129C(entry) == 0) {
            break;
        }
    }
    if (j == 0x40) {
        return -1;
    }
    return j;
}
