#pragma force_active on
struct ftManager;

extern "C" {
extern ftManager* g_ftManager;
int getPlayerNo__9ftManagerFi(ftManager*, int);
}

class Target {
    char pad[0x3C];

public:
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual void dummy22();
    virtual void dummy23();
    virtual void dummy24();
    virtual void dummy25();
    virtual void dummy26();
    virtual void dummy27();
    virtual void dummy28();
    virtual void dummy29();
    virtual void dummy30();
    virtual void dummy31();
    virtual void dummy32();
    virtual void dummy33();
    virtual void dummy34();
    virtual void dummy35();
    virtual void dummy36();
    virtual void invoke(int);
};

struct Entry {
    char pad[0x5A];
    unsigned char flag;
    char pad2;
};

struct Data {
    char pad[0x40];
    Entry entries[4];
};

struct State {
    char pad0[0xC];
    Data* data;
    char pad1[0x20];
    Target* target;
};

extern "C" void fn_27_27E9C0(State* self, int entryId) {
    if (self->target) {
        int playerNo = getPlayerNo__9ftManagerFi(g_ftManager, entryId);
        if (self->data->entries[playerNo].flag) {
            Target* target = self->target;
            target->invoke(-1);
        }
    }
}
