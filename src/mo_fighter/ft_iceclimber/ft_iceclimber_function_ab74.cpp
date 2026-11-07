#include <ft/fighter.h>
#include <so/so_external_value_accesser.h>

#pragma force_active on

#define MODULES(a) (*(unsigned char**)(*(unsigned char**)((unsigned char*)(a) + 0x60) + 0xd8))
#define FLAG(a) (((IceClimberFlag*)(a))->flag)
#define WORK(a) (*(soWorkManageModule**)(MODULES(a) + 0x64))
#define LINK(a) (*(soLinkModule**)(MODULES(a) + 0x54))
#define CAMERA(a) (*(soCameraModule**)(MODULES(a) + 0x60))
#define ITEM(a) (*(Item**)(MODULES(a) + 0xb0))

struct IceClimberFlag {
    char pad[0x1fe4c];
    unsigned char flag;
};

struct ItemBase {
    char pad[8];
};

class Item : public ItemBase {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i(bool);
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m(bool);
};

extern "C" void fn_105_AB74(Fighter* self) {
    soWorkManageModule* work;

    if (*(unsigned char*)((unsigned int)self + 0x1fe4c) == 1) {
        WORK(self)->onFlag(0x1200002e);
        WORK(self)->onFlag(0x1200003e);
        CAMERA(self)->setPri(1, -1);
        ITEM(self)->m(true);
        ITEM(self)->i(true);
    }

    {
        Fighter* partner = self->getPartner();
        if (partner && FLAG(self) == 1 && partner->isActive() == 1) {
            if (!LINK(self)->link(6, partner->m_taskId))
                return;
            LINK(self)->setAttribute(6, (soLinkConnection::Attribute)13, true);
        }
    }

    Fighter* partner = self->getPartner();
    if (partner && soExternalValueAccesser::getSituationKind(partner) != 5) {
        work = WORK(self);
        Vec3f pos = soExternalValueAccesser::getPos(partner);
        float lr = soExternalValueAccesser::getLr(partner);

        work->setInt(0, 0x10000040);
        work->setFloat(pos.m_x, 0x11000013);
        work->setFloat(pos.m_x, 0x11000014);
        work->setFloat(pos.m_x, 0x11000015);
        work->setFloat(pos.m_x, 0x11000016);
        work->setFloat(pos.m_x, 0x11000017);
        work->setFloat(pos.m_y, 0x11000018);
        work->setFloat(pos.m_y, 0x11000019);
        work->setFloat(pos.m_y, 0x1100001a);
        work->setFloat(pos.m_y, 0x1100001b);
        work->setFloat(pos.m_y, 0x1100001c);
        work->setFloat(lr, 0x1100001d);
        work->setFloat(lr, 0x1100001e);
        work->setFloat(lr, 0x1100001f);
        work->setFloat(lr, 0x11000020);
        work->setFloat(lr, 0x11000021);
    }

    WORK(self)->setInt(0, 0x10000041);
}
