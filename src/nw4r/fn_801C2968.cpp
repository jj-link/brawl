#pragma force_active on

struct Entry {
    unsigned char pad0[4];
    unsigned char enabled;
    unsigned char busy;
    unsigned char pad6[6];
    int state;
    unsigned char pad10[4];
    int result;
    unsigned char pad18[0x24];
    void (*callback)(int, int);
};

extern "C" void* fn_801C2C04();
extern "C" Entry* fn_801C2C9C(void*, int);

extern "C" void fn_801C2968(int arg0, int arg1) {
    Entry* entry = fn_801C2C9C(fn_801C2C04(), arg0);
    switch (arg1) {
    case 0:
        entry->state = 4;
        break;
    case -2:
        entry->result = 2;
        break;
    case -3:
        entry->state = 0;
        break;
    case -1:
        entry->state = 0;
        break;
    default:
        entry->state = 0;
        break;
    }
    if (arg1 != -2 && entry->enabled != 0) {
        void (*callback)(int, int) = entry->callback;
        if (callback != 0) {
            callback(arg0, arg1);
            entry->callback = 0;
        }
    }
    entry->busy = 0;
}
