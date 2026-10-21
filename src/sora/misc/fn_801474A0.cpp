#pragma force_active on

typedef unsigned long long u64;

struct FriendData {
    unsigned int data[3];
};

struct NetworkState {
    char pad[0x3440];
    u64 id;
};

extern "C" void* getInstance__12ntFriendInfoFv();
extern "C" void* fn_8014CB40(void*);
extern "C" int fn_80350CB4(void*, u64);
extern "C" void fn_80351A08(FriendData*, u64);
extern "C" char* getFriendInfo__12ntFriendInfoFv(void*);
extern "C" int fn_80351C70(FriendData*, FriendData*);
extern "C" void netReport__FPCce(const char*, ...);

extern char lbl_8045F7B8[];
extern char lbl_8045F7DC[];

extern "C" int fn_801474A0(NetworkState* self, u64 id, bool* found, bool* own) {
    *found = false;
    *own = false;

    if (fn_80350CB4(fn_8014CB40(getInstance__12ntFriendInfoFv()), id) == 0) {
        return 0;
    }

    if (id == self->id) {
        netReport__FPCce(lbl_8045F7B8);
        *own = true;
    }

    FriendData data;
    fn_80351A08(&data, id);

    FriendData* entry = (FriendData*)(
        getFriendInfo__12ntFriendInfoFv(getInstance__12ntFriendInfoFv()) + 0x50
    );

    for (int i = 0; i < 64; ++i, ++entry) {
        if (fn_80351C70(entry, &data) == 1) {
            netReport__FPCce(lbl_8045F7DC);
            *found = true;
            break;
        }
    }

    return 1;
}
