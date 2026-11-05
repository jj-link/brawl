#include <nw4r/ut/ut_LinkList.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern "C" void fn_801FF4CC(void*);
extern "C" void* fn_801B885C(void*, int);

class List : public nw4r::ut::detail::LinkListImpl {
public:
    using nw4r::ut::detail::LinkListImpl::Erase;
    using nw4r::ut::detail::LinkListImpl::Insert;
    using nw4r::ut::detail::LinkListImpl::GetEndIter;
};

extern "C" void fn_801BB8E0(char* list, char* obj) {
    BOOL a = OSDisableInterrupts();
    if (*(void**)obj)
        fn_801FF4CC(*(void**)obj);
    fn_801B885C(obj, -1);
    BOOL b = OSDisableInterrupts();
    nw4r::ut::LinkListNode* node;
    if (((unsigned char*)obj)[0x1d]) {
        node = (nw4r::ut::LinkListNode*)(obj + 0x40);
        ((List*)(list + 0x18))->Erase(node);
    } else {
        node = (nw4r::ut::LinkListNode*)(obj + 0x40);
        ((List*)list)->Erase(node);
    }
    ((List*)(list + 0xc))->Insert(((List*)(list + 0xc))->GetEndIter(), node);
    OSRestoreInterrupts(b);
    OSRestoreInterrupts(a);
}