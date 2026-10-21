#pragma force_active on

struct DonkeyAccesser;

struct DonkeyEventHandler {
    unsigned char padding[0x60];
    DonkeyAccesser* accesser;
};

class DonkeyStatusModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual bool changeStatusRequest(int, DonkeyAccesser*);
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual int getStatusKind();
};

class DonkeyModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void set(int);
};

struct DonkeyModules {
    unsigned char padding00[0x3C];
    DonkeyModule* module;
    unsigned char padding40[0x30];
    DonkeyStatusModule* status;
};

struct DonkeyAccesser {
    unsigned char padding[0xD8];
    DonkeyModules* modules;
};

extern "C" void fn_27_1324D4(
    DonkeyEventHandler*, int*, DonkeyAccesser*, void*, int);

extern "C" void fn_92_8EE4(
    DonkeyEventHandler* self,
    int* event,
    DonkeyAccesser* accesser,
    void* object,
    int eventType)
{
    DonkeyStatusModule* status = accesser->modules->status;
    int kind = status->getStatusKind();

    switch (*event) {
    case 0x453:
        if (kind >= 0x120 && kind <= 0x129) {
            status->changeStatusRequest(0x3B, self->accesser);
            return;
        }
        break;

    case 9:
        if (kind >= 0x120 && kind <= 0x129) {
            accesser->modules->module->set(0);
            status->changeStatusRequest(0x3B, self->accesser);
            return;
        }
        break;
    }

    fn_27_1324D4(self, event, accesser, object, eventType);
}
