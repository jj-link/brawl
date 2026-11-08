#include <revolution/OS/OSTime.h>
#include <revolution/OS/OSThread.h>
#include <nt/nt_offline.h>
#pragma force_active on

extern "C" {
int fn_800305B0(int);
int fn_8014CB40(ntFriendInfo*);
int fn_8014CB4C(ntFriendInfo*, int);
void fn_8014CB7C(ntFriendInfo*);
void fn_8014FEFC();
int fn_801515B4(void*, void*, const char*, const char*);
int fn_801516D4(void*, void*);
int fn_801517D0(void*, void*, const char*, const char*, const char*);
}

extern unsigned char lbl_80423690[];
extern char lbl_804620B0[];
extern char lbl_8059E818[5];
extern char lbl_8059E820[8];
extern char lbl_8059E828[1];
extern char lbl_8059E82C[6];

#define TICKS ((*(u32*)0x800000F8 / 4) / 1000)
#define EXPIRED (!(self->timeout == 0 ? true : OSGetTime() <= start + self->timeout * TICKS))

struct Context {
    char pad0[0x190];
    int count;
};

struct Handler {
    char pad0[0x34d];
    unsigned char ready;
};

struct Task {
    char pad0[0x344];
    char base[4];
    unsigned char finished;
    char pad349[3];
    int result;
    char pad350[4];
    int mode;
    char pad358[4];
    unsigned char done;
    char pad35d[3];
    unsigned int timeout;
    char pad364[12];
    Context* context;
    unsigned char busy;
    char pad375[3];
    Handler* handler;
    unsigned char cancel;
    unsigned char setting;
    unsigned char deliver;
};

static inline void* taskBase(Task* self) {
    void* result = self;
    if (self)
        result = self->base;
    return result;
}

extern "C" void fn_8015741C(Task* self) {
    if (self->cancel)
        return;

    self->result = 1;
    self->cancel = 0;
    s64 start = OSGetTime();

    if (self->deliver == 1) {
        if (fn_800305B0(3)) {
            unsigned char* global = lbl_80423690;
            if (!global[0])
                self->context->count++;

            while (!global[0]) {
                if (EXPIRED)
                    goto finish;
                OSSleepTicks(TICKS);
            }

            if ((*(u32*)(global + 12) << 17) < 0x4b000U)
                self->deliver = 0;
        } else {
            self->deliver = 0;
        }
    }

    int value = fn_8014CB40(ntFriendInfo::getInstance());
    if (!fn_8014CB4C(ntFriendInfo::getInstance(), value)) {
        fn_8014CB7C(ntFriendInfo::getInstance());
        fn_8014CB40(ntFriendInfo::getInstance());
    }

    if (!fn_801515B4(self->handler, taskBase(self),
                     lbl_8059E818, lbl_804620B0))
        goto finish;

    self->busy = 0;
    while (!self->handler->ready) {
        if (self->cancel)
            goto finish;
        if (EXPIRED)
            goto finish;
        OSSleepTicks(TICKS);
    }

    if (self->setting) {
        self->mode = 1;
        self->done = 0;
        if (!fn_801517D0(self->handler, taskBase(self),
                         lbl_8059E820, lbl_8059E828, lbl_8059E828))
            goto disconnect;

        while (!self->done) {
            if (self->cancel)
                goto disconnect;
            if (EXPIRED)
                goto disconnect;
            OSSleepTicks(TICKS);
        }
    }

    fn_8014FEFC();
    if (self->deliver) {
        self->mode = 2;
        self->done = 0;
        if (!fn_801517D0(self->handler, taskBase(self),
                         lbl_8059E82C, lbl_8059E828, lbl_8059E828))
            goto disconnect;

        while (!self->done) {
            if (self->cancel)
                goto disconnect;
            if (EXPIRED)
                goto disconnect;
            OSSleepTicks(TICKS);
        }
    }

    self->result = 0;

disconnect:
    if (fn_801516D4(self->handler, taskBase(self))) {
        while (self->handler->ready)
            OSSleepTicks(TICKS);
    }

finish:
    self->finished = 1;
    self->busy = 1;
}
