#include <nw4r/ut/ut_LinkList.h>
#include <revolution/OS.h>

#pragma force_active on

typedef unsigned char u8;

struct Node {
    Node* next;
    Node* prev;
};

struct Manager {
    int field0;
    int size;
    Node head;
    u8 field10;
    int field14;
    int field18;
    int field1c;
};

struct Object {
    u8 pad0[0x31];
    u8 field31;
    u8 field32;
    u8 field33;
    u8 pad34[0xA0];
    void (*callback)(Object*, int, int);
    int arg;
    void* handle;
    int fielde0;
    Node node;
};

struct IntState {
    BOOL v;
};

inline IntState lockInts() {
    IntState s;
    s.v = OSDisableInterrupts();
    return s;
}

inline void unlockInts(IntState s) {
    OSRestoreInterrupts(s.v);
}

typedef nw4r::ut::LinkList<Object, 0xE4> ObjectList;

extern "C" {
extern Manager lbl_804C1CC8;
extern u8 lbl_805A0580;
extern u8 lbl_804C1CB8[0x10];

void fn_801D1140(void*);
void fn_801D0DA4(void*);
void fn_801BD71C(void*);
void __register_global_object(void*, void (*)(void*), void*);
void fn_801C0A68(Manager*, Object*);
void fn_801C093C(Manager*, int, int);
}

inline Manager* getManager() {
    if ((signed char)lbl_805A0580 == 0) {
        lbl_804C1CC8.head.next = 0;
        Node* head = &lbl_804C1CC8.head;
        lbl_804C1CC8.head.prev = 0;
        lbl_804C1CC8.field0 = 0;
        lbl_804C1CC8.size = 0;
        head->next = head;
        head->prev = head;
        lbl_804C1CC8.field10 = 0;
        lbl_804C1CC8.field14 = 0;
        __register_global_object(&lbl_804C1CC8, fn_801BD71C, lbl_804C1CB8);
        lbl_805A0580 = 1;
    }
    return &lbl_804C1CC8;
}

extern "C" void fn_801BD838(Manager* self) {
    IntState enabled = lockInts();
    if (!self->field10) {
        unlockInts(enabled);
        return;
    }

    ObjectList& list = *(ObjectList*)&self->size;
    for (ObjectList::Iterator __impl__ = list.GetBeginIter();
         __impl__ != list.GetEndIter();) {
        ObjectList::Iterator it = __impl__++;
        Object* obj = &*it;
        if (obj->handle) {
            fn_801D1140(obj->handle);
            fn_801D0DA4(obj->handle);
            obj->handle = 0;
            obj->field31 = 0;
            obj->field32 = 0;

            if (obj->field33) {
                obj->field33 = 0;
                Manager* manager = getManager();
                ((ObjectList*)&manager->size)->Erase(obj);
                if (obj) {
                    fn_801C0A68(manager, obj);
                }
            }

            if (obj->callback) {
                obj->callback(obj, 0, obj->arg);
            }
        }
    }

    fn_801C093C(self, self->field18, self->field1c);
    self->field10 = 0;
    unlockInts(enabled);
}
