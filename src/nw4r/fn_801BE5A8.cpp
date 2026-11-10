#include <types.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on

struct Manager {
    void* m0;
    void* m4;
    void* m8;
    void* mC;
    u8 m10;
    void* m14;
};
class List : public nw4r::ut::detail::LinkListImpl {
public:
    using LinkListImpl::Insert;
    using LinkListImpl::Erase;
    using LinkListImpl::GetEndIter;
};
extern "C" {
extern u8 lbl_805A0580;
extern Manager lbl_804C1CC8;
extern u8 lbl_804C1CB8[0x10];
extern f32 lbl_805A34B8;
void fn_801BD71C(void*);
void fn_801BE47C(void);
void __register_global_object(void*, void*, void*);
void* fn_801C0A0C(void*);
void fn_801BF0FC(void*);
void fn_801C0AB0(void*);
void fn_801C0A68(void*, void*);
int fn_801D2AD0(void);
int fn_801D2D74(int, int, int, int, void*, void*);
void fn_801BD9E8(void*, int, int);
}
inline Manager* manager() {
    if ((s8)lbl_805A0580 == 0) {
        void* p;
        lbl_804C1CC8.m8 = 0;
        p = &lbl_804C1CC8.m8;
        lbl_804C1CC8.mC = 0;
        lbl_804C1CC8.m0 = 0;
        lbl_804C1CC8.m4 = 0;
        lbl_804C1CC8.m8 = p;
        lbl_804C1CC8.mC = p;
        lbl_804C1CC8.m10 = 0;
        lbl_804C1CC8.m14 = 0;
        __register_global_object(&lbl_804C1CC8, (void*)fn_801BD71C, lbl_804C1CB8);
        lbl_805A0580 = 1;
    }
    return &lbl_804C1CC8;
}
inline void* create(Manager* mgr) {
    void* obj = fn_801C0A0C(mgr);
    if (!obj) return 0;
    if (obj) {
        fn_801BF0FC(obj);
        fn_801C0AB0((char*)obj + 0x18);
        *(s32*)((char*)obj + 0x28) = 0;
        *(f32*)((char*)obj + 0x2C) = 0.0f;
        *(u8*)((char*)obj + 0x31) = 0;
        *(u8*)((char*)obj + 0x32) = 0;
        *(u8*)((char*)obj + 0x33) = 0;
        *(u8*)((char*)obj + 0xB8) = 0;
        *(u8*)((char*)obj + 0xB9) = 0;
        *(s16*)((char*)obj + 0xBA) = 0;
        *(s16*)((char*)obj + 0xBC) = 0;
        *(s32*)((char*)obj + 0xDC) = 0;
        *(s32*)((char*)obj + 0xE4) = 0;
        *(s32*)((char*)obj + 0xE8) = 0;
    }
    return obj;
}
extern "C" void* fn_801BE5A8(int arg0, int arg1, int arg2, int arg3, int arg4) {
    Manager* mgr = manager();
    void* obj = create(mgr);
    nw4r::ut::LinkListNode* node = (nw4r::ut::LinkListNode*)((char*)obj + 0xE4);
    ((List*)((char*)mgr + 4))->Insert(nw4r::ut::detail::LinkListImpl::Iterator((nw4r::ut::LinkListNode*)((char*)mgr + 8)), node);
    if (!obj) return 0;
    *(u8*)((char*)obj + 0x33) = 1;
    int r = fn_801D2D74(fn_801D2AD0(), arg0, arg1, arg2, (void*)fn_801BE47C, obj);
    if (!r) {
        mgr = manager();
        ((List*)((char*)mgr + 4))->Erase(node);
        if (obj) fn_801C0A68(mgr, obj);
        return 0;
    }
    *(s32*)((char*)obj + 0xDC) = r;
    fn_801BD9E8(obj, arg3, arg4);
    return obj;
}