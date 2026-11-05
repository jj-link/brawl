#pragma force_active on

typedef unsigned int u32;

struct Receiver {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int func(u32, void*);
};

struct StatusModule {
    char pad[0x64];
    Receiver* receiver;
};

struct Accesser {
    char pad[0xD8];
    StatusModule* status;
};

struct Fighter {
    char pad0[0x60];
    Accesser* accesser;
    char pad1[0x864];
    u32 id;
};

struct Event {
    char pad[0xC];
    u32 id;
};

extern "C" int fn_27_29EEA0(void*, Fighter* fighter, const Event* event) {
    if (event->id == fighter->id) {
        Accesser* accesser = fighter->accesser;
        Receiver* receiver = accesser->status->receiver;
        if (receiver->func(0x1000000B, accesser) > 0) {
            return 0;
        }
    }
    return 1;
}
