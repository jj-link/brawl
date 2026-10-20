#include <types.h>
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

class soModuleAccesser;
class soEventObserverRegistrationDesc;

class gfTask {
public:
    enum Category {
        CategoryDefault = 0,
    };
};

class soCollisionHitPart;
class soCollisionGroup;
class soCollisionHitGroup;

template <class T>
class soArray;

class soCollisionHitModuleImpl {
public:
    soCollisionHitModuleImpl(soModuleAccesser* moduleAccesser, int taskId,
                             gfTask::Category taskCategory,
                             soArray<soCollisionHitPart>* hitPartArray,
                             soArray<soCollisionGroup>* collisionGroupArray,
                             soArray<soCollisionHitGroup>* collisionHitGroupArray,
                             soEventObserverRegistrationDesc* registrationDesc,
                             bool param8);
};

extern char lbl_41_data_3C70[];
extern char lbl_27_bss_A48[];

// Layout of the enemy collision-hit module: the soCollisionHitModuleImpl base
// (0x00-0x67) plus the stored registration descriptor and flag.
struct EmCollisionHitModule {
    void* m_vptr;
    unsigned char m_pad04[4];
    void* m_vptrStatusObserver;
    unsigned char m_pad0C[8];
    void* m_vptrAnimCmdObserver;
    unsigned char m_pad18[8];
    void* m_vptrEventPresenter;
    unsigned char m_pad28[0x44];
    void* m_desc;
    u32 m_flag;
};

extern "C" EmCollisionHitModule* fn_41_2B8FC(
    EmCollisionHitModule* self, soModuleAccesser* accesser, int taskId,
    gfTask::Category taskCategory, soArray<soCollisionHitPart>* hitPartArray,
    soArray<soCollisionGroup>* collisionGroupArray,
    soArray<soCollisionHitGroup>* collisionHitGroupArray,
    soEventObserverRegistrationDesc* registrationDesc, int flag) {
    new (reinterpret_cast<soCollisionHitModuleImpl*>(self))
        soCollisionHitModuleImpl(accesser, taskId, taskCategory, hitPartArray,
                                 collisionGroupArray, collisionHitGroupArray,
                                 reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48),
                                 true);
    const char* vtable = lbl_41_data_3C70;
    self->m_vptr = const_cast<char*>(vtable);
    self->m_vptrStatusObserver = const_cast<char*>(vtable + 0xDC);
    self->m_vptrAnimCmdObserver = const_cast<char*>(vtable + 0xEC);
    self->m_vptrEventPresenter = const_cast<char*>(vtable + 0x100);
    self->m_desc = registrationDesc;
    self->m_flag = flag;
    return self;
}
