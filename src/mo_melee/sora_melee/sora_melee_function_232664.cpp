#include <types.h>
#pragma force_active on

struct ListBase {
    ListBase* next;
};

class ListEntryA : public ListBase {
public:
    virtual void vf0();
};

class ListEntryB : public ListBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

struct Node {
    Node* next;
    char pad0[0x14];
    ListEntryA* listA;
    char pad1[4];
    ListEntryB* listB;
    ListEntryB* listC;
    ListEntryB* listD;
    char pad2[3];
    unsigned char flag;
};

struct Owner {
    char pad[0x40];
    Node* head;
    char pad2[0x1c];
    unsigned char enabled;
};

extern "C" {
extern char lbl_27_data_4BCF8[];
extern char __RTTI__10gfCallBack[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_234B10(void*);
u32 fn_8004E958(s32 p);
}
extern "C" s32 g_GameGlobal;

extern "C" void fn_27_232664(Owner* self) {
    Node* node = self->head;
    if (self->enabled) {
        while (node) {
            if (fn_8004E958(g_GameGlobal)) {
                if (node->listA && !node->flag) {
                    fn_27_234B10(node->listA);
                }
                ListEntryA* a = node->listA;
                if (a) {
                    a->vf0();
                    a = (ListEntryA*)a->next;
                    while (a) {
                        a->vf0();
                        a = (ListEntryA*)a->next;
                    }
                }
                ListEntryB* b = node->listC;
                while (b) {
                    b->vf2();
                    b = (ListEntryB*)__dynamic_cast(b->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
                }
                b = node->listB;
                while (b) {
                    b->vf2();
                    b = (ListEntryB*)__dynamic_cast(b->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
                }
                b = node->listD;
                while (b) {
                    b->vf2();
                    b = (ListEntryB*)__dynamic_cast(b->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
                }
            }
            node = node->next;
        }
    }
}
