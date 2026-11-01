struct CaptainStatusModule {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual bool changeStatusRequest(int status, void* accesser);
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual int getStatusKind();
};

struct CaptainWorkModule {
    virtual void w00();
    virtual void w04();
    virtual void w08();
    virtual void w0C();
    virtual void w10();
    virtual void w1C(void* p);
    virtual void w20();
    virtual void w24();
    virtual void w28();
    virtual void w2C();
    virtual void w30();
    virtual void w34();
    virtual void w38(int x);
    virtual void w3C();
    virtual void w40(int x);
};

struct CaptainEnumStart {
    unsigned char pad1[0x3C];
    CaptainWorkModule* m_workModule;
    unsigned char pad2[0x30];
    CaptainStatusModule* m_statusModule;
};

struct soModuleAccesser {
    unsigned char pad1[0xD8];
    CaptainEnumStart* m_enumStart;
};

struct CaptainFighter {
    unsigned char pad1[0x60];
    soModuleAccesser* m_accesser;
};

struct CaptainLinkObject {
    unsigned char pad[0x28];
    void* field28;
};

struct CaptainEvent {
    int m_kind;
    unsigned char unk4;
    unsigned char unk5;
    unsigned char pad1[6];
    int unkC;
    unsigned char pad2[12];
    unsigned char unk1C;
};

extern "C" void fn_100_F3B0(CaptainEvent*, soModuleAccesser*, void*, int);
extern "C" void fn_27_1324D4(CaptainFighter*, CaptainEvent*, soModuleAccesser*, void*, int);

#pragma force_active on
extern "C" void fn_100_8C7C(CaptainFighter* self, CaptainEvent* event,
                            soModuleAccesser* accesser, CaptainLinkObject* object, int value) {
    switch (event->m_kind) {
    case 0x8:
        if (event->unkC == 0xCF) {
            if (self->m_accesser->m_enumStart->m_statusModule->getStatusKind() == 0x114) {
                self->m_accesser->m_enumStart->m_statusModule->changeStatusRequest(
                    0x119, self->m_accesser);
                event->unk4 = 1;
                event->unk1C = 0;
                self->m_accesser->m_enumStart->m_workModule->w1C(object->field28);
                return;
            }
        }
        break;

    case 0xE: {
        int kind = self->m_accesser->m_enumStart->m_statusModule->getStatusKind();
        switch (kind) {
        case 0x119:
        case 0x11A:
            self->m_accesser->m_enumStart->m_workModule->w40(0);
            self->m_accesser->m_enumStart->m_workModule->w38(0);
            if (event->unk5 != 0)
                return;
            self->m_accesser->m_enumStart->m_statusModule->changeStatusRequest(
                0x3B, self->m_accesser);
            return;
        default:
            goto captain_general;
        }
    }

    case 0x3D: {
        int kind = accesser->m_enumStart->m_statusModule->getStatusKind();
        if (kind >= 0x11D)
            goto captain_high;
        if (kind == 0x116)
            goto captain_special;
        break;

    captain_high:
        if (kind >= 0x122)
            break;

    captain_special:
        fn_100_F3B0(event, accesser, object, value);
        break;
    }

    default:
        goto captain_general;
    }

captain_general:
    fn_27_1324D4(self, event, accesser, object, value);
}
