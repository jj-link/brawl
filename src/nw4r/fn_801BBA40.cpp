#pragma force_active on
#pragma opt_loop_invariants off
#include <nw4r/ut/ut_LinkList.h>
#include <revolution/OS/OSInterrupt.h>

struct Item {
    void* inner;
    char pad4[0x19];
    u8 flag;
    char pad1e[0x1A];
    void (*callback)(Item*, int, int);
    int arg;
};
struct Manager {
    char pad0[0x18];
    int count;
    nw4r::ut::LinkListNode* head;
};
struct ListAccess : nw4r::ut::detail::LinkListImpl {
    using nw4r::ut::detail::LinkListImpl::Erase;
    using nw4r::ut::detail::LinkListImpl::Insert;
};
extern "C" {
extern int lbl_804C1C8C[11];
extern u8 lbl_804C1C80[12];
extern u8 lbl_805A0568;
void fn_801BB22C(void*, int);
void __register_global_object(void*, void*, void*, void*, void*, void*);
void fn_801FF4CC(void*);
void fn_801B885C(void*, int);
}

inline int* GetManager() {
    if ((s8)lbl_805A0568 == 0) {
        int* base = lbl_804C1C8C;
        int* p1;
        int* p2;
        int* p3;
        p1 = &base[1];
        base[1] = 0;
        p2 = &base[4];
        p3 = &base[7];
        base[2] = 0;
        base[4] = 0;
        base[5] = 0;
        base[7] = 0;
        base[8] = 0;
        base[0] = 0;
        base[1] = (int)p1;
        base[2] = (int)p1;
        base[3] = 0;
        base[4] = (int)p2;
        base[5] = (int)p2;
        base[6] = 0;
        base[7] = (int)p3;
        base[8] = (int)p3;
        ((u8*)base)[36] = 0;
        __register_global_object(base, (void*)fn_801BB22C, lbl_804C1C80, p1, p2, p3);
        lbl_805A0568 = 1;
    }
    return lbl_804C1C8C;
}

struct IntState { int v; };
inline IntState lockInts() { IntState s; s.v = OSDisableInterrupts(); return s; }
inline void unlockInts(IntState s) { OSRestoreInterrupts(s.v); }
extern "C" void fn_801BBA40(Manager* self) {
    if (self->count != 0) {
        while (self->count != 0) {
            IntState s1;
            IntState s2;
            nw4r::ut::LinkListNode* head = self->head;
            Item* obj = (Item*)((char*)head - 0x40);
            if (obj->callback != 0)
                obj->callback(obj, 1, obj->arg);
            int* manager = GetManager();
            s1 = lockInts();
            void* inner = obj->inner;
            if (inner != 0)
                fn_801FF4CC(inner);
            fn_801B885C(obj, -1);
            s2 = lockInts();
            nw4r::ut::LinkListNode* n;
            if (obj->flag != 0) {
                n = (nw4r::ut::LinkListNode*)((char*)obj + 0x40);
                ((ListAccess*)((char*)manager + 0x18))->Erase(n);
            } else {
                n = (nw4r::ut::LinkListNode*)((char*)obj + 0x40);
                ((ListAccess*)manager)->Erase(n);
            }
            nw4r::ut::detail::LinkListImpl::Iterator it((nw4r::ut::LinkListNode*)((char*)manager + 0x10));
            ((ListAccess*)((char*)manager + 0xC))->Insert(it, n);
            unlockInts(s2);
            unlockInts(s1);
        }
    }
}
