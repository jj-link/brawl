#include <ft/ft_manager.h>
#include <revolution/OS/OSError.h>
#pragma force_active on

class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual void fn_27_100D0(int, int);
    virtual void fn_27_100CC();
    virtual void fn_27_10094();
    virtual void fn_27_100C8(int);
};
struct PlayerRecord {
    unsigned char kind;
    char pad1[0x1b];
    unsigned char flags : 1;
    char pad2[0x3f];
};
struct PlayerData {
    char pad[0x98];
    PlayerRecord player[1];
};
struct EntryRecord {
    char pad[0x12];
    unsigned char active;
    char tail[1];
};
struct EntryData {
    char pad[4];
    unsigned char mode;
    char pad2[0xf];
    EntryRecord entries[1];
};
struct Work {
    char pad0[0x44];
    PlayerData* data;
    char pad48[0xc];
    Class_CF8* callback;
    char pad58[0x1c];
    unsigned char disabled;
    char pad75[0x5d];
    unsigned char flagD2;
    char padD3;
    unsigned char flagD4;
    char padD5[7];
    unsigned char flagDC;
    char padDD[7];
    int defaultSleep;
    char padE8[0x1c];
    int count;
    int sleep[7];
    int altSleep[7];
    int reasons[7];
    char pad15c[0x5c];
    int threshold;
    char pad1bc[8];
    int total;
    char pad1c8[4];
    int remaining;
    char pad1d0[0xc];
    EntryData* entryData;
    char pad1e0[0xc];
    int dead[7];
    int entries[7];
};
extern "C" int fn_27_10B234(ftManager*, int);
extern "C" void fn_27_248478(Work*);
extern "C" char lbl_27_data_4F0BC[];

extern "C" int fn_27_249B14(Work* self, int entry, int player, int reason) {
    if (self->disabled)
        return 0;
    if (player < self->count) {
        ftManager* manager = g_ftManager;
        int no = manager->getPlayerNo(fn_27_10B234(manager, entry));
        int* sleep;
        if (!(self->data->player[no].flags)) {
            self->sleep[no] = self->defaultSleep;
            sleep = &self->sleep[no];
        } else {
            int value = self->altSleep[no];
            value = value ? value : self->defaultSleep;
            self->sleep[no] = value;
            sleep = &self->sleep[no];
        }
        OSReport(lbl_27_data_4F0BC, no, *sleep, sleep);
        if (self->data->player[player].kind < 0x2e)
            self->reasons[player] = reason;
        else
            self->reasons[player] = 0x2d;
    }
    if (self->callback)
        self->callback->fn_27_100D0(entry, player);
    bool alive;
    if (self->flagD2)
        alive = false;
    else if (self->flagDC) {
        if (!g_ftManager->isValidEntryId(entry))
            alive = false;
        else
            alive = g_ftManager->getOwner(entry)->getStockCount() != 0;
    } else
        alive = true;
    if (!alive && self->flagD4 && self->threshold <= player) {
        if (self->total < 0x05f5e0ff)
            self->total++;
        self->remaining--;
        self->dead[player] = 1;
        if (self->callback && self->entries[player] >= 0)
            self->callback->fn_27_100C8(self->entries[player]);
        if (self->entryData->mode == 1) {
            if (self->entries[player] >= 0) {
                self->entryData->entries[self->entries[player]].active = 0;
                self->entries[player] = -1;
            }
            fn_27_248478(self);
        }
    }
    return alive;
}