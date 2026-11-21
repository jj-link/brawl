#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on
using namespace nw4r::ut;
class ListAccess : public detail::LinkListImpl {
public:
    using detail::LinkListImpl::Insert;
    using detail::LinkListImpl::Erase;
};
extern "C" void fn_801BD2EC();
extern "C" void fn_801C4748(char* self) {
    OSMutex* mutex;
    fn_801BD2EC();
    char* list;
    int a = *(unsigned char*)(self + 0x74) + *(int*)(self + 0x40);
    int x = a > 127 ? 127 : (a < 0 ? 0 : a);
    list = *(char**)(self + 0x1f8);
    mutex = (OSMutex*)(list + 0x10);
    OSLockMutex(mutex);
    char* node = self + 0xb8;
    ((ListAccess*)(list + 0x4))->Erase((LinkListNode*)node);
    detail::LinkListImpl::Iterator it(*(LinkListNode**)(list + 0x8));
    while (!(it == detail::LinkListImpl::Iterator((LinkListNode*)(list + 0x8)))) {
        int b = *(unsigned char*)((char*)it.operator->() - 0x44) + *(int*)((char*)it.operator->() - 0x78);
        int y = b > 127 ? 127 : (b < 0 ? 0 : b);
        if (x < y) break;
        ++it;
    }
    ((ListAccess*)(list + 0x4))->Insert(it, (LinkListNode*)node);
    OSUnlockMutex(mutex);
}