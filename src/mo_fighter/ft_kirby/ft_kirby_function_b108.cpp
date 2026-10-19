#pragma force_active on
extern "C" void fn_27_13138C(void*);
extern "C" void fn_96_1D92C(void*, int, int, void*, void*);
extern "C" void fn_96_D5C4(void*, void*, int);

struct LinkEvent {
    int id;
    char flag;
};

struct QueryObject {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual int getCurrent(unsigned int) = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual int has(unsigned int) = 0;
};

struct LinkObject {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void send(int, LinkEvent*, int) = 0;
};

struct StatusObject {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void setStatus(int, int) = 0;
};

#define MODULES(a) (*reinterpret_cast<void**>(reinterpret_cast<char*>(a) + 0xD8))
#define FIELD(a, o) (*reinterpret_cast<void**>(reinterpret_cast<char*>(a) + (o)))

extern "C" void fn_96_B108(void* self, int status, int previous,
                           void* data, void* accesser) {
    fn_27_13138C(self);
    fn_96_1D92C(reinterpret_cast<char*>(self) + 0x1B72C,
                status, previous, data, accesser);

    switch (status) {
    case 0x10C:
        if (reinterpret_cast<QueryObject*>(FIELD(MODULES(accesser), 0x64))
                ->has(0x12000042)) {
            fn_96_D5C4(self, accesser, 1);
        }
        break;
    case 0xBD:
        fn_96_D5C4(self, accesser, 0);
        break;
    case 0x12E:
    case 0x12F:
    case 0x130:
    case 0x131:
    case 0x132: {
        LinkEvent event;
        event.id = 0x83A;
        event.flag = 0;
        reinterpret_cast<LinkObject*>(FIELD(MODULES(accesser), 0x54))
            ->send(1, &event, 0);
        break;
    }
    case 0x0D:
        if (reinterpret_cast<QueryObject*>(
                FIELD(MODULES(accesser), 0x64))->has(0x12000042)) {
            int current = reinterpret_cast<QueryObject*>(
                FIELD(MODULES(accesser), 0x64))->getCurrent(0x10000048);
            if (current != 0x0F && current != 0x10 && current != 0x16 &&
                current != 0x0E && current != 0x03 && current != 0x09 &&
                current != 0x15 && current != 0x31 && current != 0x14) {
                reinterpret_cast<StatusObject*>(
                    FIELD(MODULES(accesser), 0x58))->setStatus(1, 1);
            }
        } else {
            reinterpret_cast<StatusObject*>(FIELD(MODULES(accesser), 0x58))
                ->setStatus(1, 1);
        }
        break;
    }
}
