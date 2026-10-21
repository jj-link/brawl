#pragma force_active on
struct Event {
    int kind;
    bool flag;
    int duration;

    Event(int frames) : kind(0x83F), flag(false), duration(frames) {}
};

struct Stop {
    unsigned char pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual int get();
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(int);
    virtual void setInt(int, int);
};

struct Link {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void send(int, Event*);
};

struct Modules {
    unsigned char pad0[0x54];
    Link* link;
    unsigned char pad1[0xC];
    Work* work;
    unsigned char pad2[0x34];
    Stop* stop;
};

struct Self {
    unsigned char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_113_2DCE4(Self* self) {
    Stop* stop = self->modules->stop;
    int duration = stop->get();
    Work* work = self->modules->work;

    if (duration != work->getInt(0x10000008)) {
        work = self->modules->work;
        int maximum = work->getInt(0x10000007);
        if (duration > maximum)
            duration = maximum;

        Event event(duration);
        Link* link = self->modules->link;
        link->send(3, &event);

        work = self->modules->work;
        work->setInt(duration, 0x10000008);
    }
}
