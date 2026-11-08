#pragma force_active on

typedef unsigned long long u64;
typedef unsigned int u32;
typedef int s32;

struct NetworkState {
    char pad[0x3440];
    u64 id;
};

struct FriendData {
    u32 data[3];
};

extern "C" {
void* getInstance__12ntFriendInfoFv();
int fn_8014CB40(int*);
int fn_80350CB4(void*, u64);
void fn_80351A08(FriendData*, u64);
char* getFriendInfo__12ntFriendInfoFv(void*);
s32 fn_801483A4(u64);
void netReport__FPCce(const char*, ...);
void fn_8014CB1C(void*, int);
void fn_80339E98(int, void*, int, void*, int, void*, int);
void* memset(void*, int, unsigned long);
void fn_80148210();
void fn_80148280();
void fn_801482C8();
}

extern char lbl_8045F7A8[];

extern "C" s32 fn_801475A4(NetworkState* self, s32 index, u64 id, s32 flag) {
    const char* base = lbl_8045F7A8;
    s32 idx = flag;
    netReport__FPCce(base + 0x70);

    if (id == self->id) {
        netReport__FPCce(base + 0x88);
        return -3;
    }

    int found = fn_80350CB4(
        (void*)fn_8014CB40((int*)getInstance__12ntFriendInfoFv()), id);
    if (found == 0) {
        netReport__FPCce(base + 0xa8);
        return -2;
    }

    flag = index;
    if (index < 0)
        flag = fn_801483A4(id);

    if (flag < 0) {
        netReport__FPCce(base + 0xc8);
        return -1;
    }

    if (idx)
        return 0;

    fn_80351A08(
        (FriendData*)(getFriendInfo__12ntFriendInfoFv(
            getInstance__12ntFriendInfoFv()) + flag * 0xc + 0x50),
        id);
    fn_80339E98(0, (void*)fn_80148210, 0, (void*)fn_80148280,
                0, (void*)fn_801482C8, 0);

    if (index < 0) {
        char* b = (char*)*(int*)getInstance__12ntFriendInfoFv() + flag * 4;
        b[0x350] = 0;
        b[0x351] = 0;
        b[0x352] = 0;
        b[0x353] = 0;

        char* entry = (char*)*(int*)getInstance__12ntFriendInfoFv()
                      + flag * 0x89;
        char* p = entry + 0x581;
        memset(p, 0, 0xa);
        memset(p + 0xa, 0, 0xa);
        memset(p + 0x3b, 0, 0x4c);
        memset(p + 0x32, 0, 8);
        p[0x3a] = 0;
        p[0x87] = 0;
        p[0x88] = 0;
    }

    fn_8014CB1C(getInstance__12ntFriendInfoFv(), 1);
    return flag;
}
