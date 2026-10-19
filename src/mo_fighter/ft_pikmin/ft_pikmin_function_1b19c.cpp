#pragma force_active on
struct StatusModule {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual int getStatusKind();
};

struct ModuleTable {
    unsigned char padding[0x70];
    StatusModule* status;
};

struct ModuleAccesser {
    unsigned char padding[0xd8];
    ModuleTable* modules;
};

struct PikminObject {
    unsigned char padding[0x60];
    ModuleAccesser* accesser;
};

extern "C" void fn_27_1DA534(void*, void*);

extern "C" void fn_113_1B19C(PikminObject* self, void* arg) {
    StatusModule* status = self->accesser->modules->status;
    switch (status->getStatusKind()) {
    case 0x1e:
    case 0x1f:
    case 0x2c:
        return;
    default:
        break;
    }
    fn_27_1DA534(self, arg);
}
