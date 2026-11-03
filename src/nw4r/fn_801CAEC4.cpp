#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on
using namespace nw4r::ut;
class ListAccess : public detail::LinkListImpl {
public:
    using detail::LinkListImpl::Insert;
};
extern "C" void fn_801CAEC4(char* self, char* obj) {
    OSMutex* mutex = (OSMutex*)(self + 0x48);
    OSLockMutex(mutex);
    detail::LinkListImpl::Iterator it(*(LinkListNode**)(self + 0x10));
    while (!(it == detail::LinkListImpl::Iterator((LinkListNode*)(self + 0x10)))) {
        int a = *(unsigned char*)((char*)it.operator->() - 0x54) + *(int*)((char*)it.operator->() - 0x88);
        int x = a > 127 ? 127 : (a < 0 ? 0 : a);
        int b = *(unsigned char*)(obj + 0x74) + *(int*)(obj + 0x40);
        int y = b > 127 ? 127 : (b < 0 ? 0 : b);
        if (y < x) break;
        ++it;
    }
    ((ListAccess*)(self + 0xc))->Insert(it, (LinkListNode*)(obj + 0xc8));
    OSUnlockMutex(mutex);
}