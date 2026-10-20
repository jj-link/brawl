#include <types.h>
#include <ft/ft_manager.h>
#pragma force_active on

class ftEntryCountIface {
public:
    virtual ~ftEntryCountIface();
    virtual void slot2();
    virtual void slot3();
    virtual int getCount();
};

struct ftEntryCountHolder {
    char _0x0[8];
    ftEntryCountIface iface;
};

int ftManager::getEntryCount() {
    ftEntryCountIface* p = &reinterpret_cast<ftEntryCountHolder*>(m_entryManager)->iface;
    return p->getCount();
}
