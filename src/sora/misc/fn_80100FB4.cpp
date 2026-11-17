#include <mu/mu_object.h>
#include <ut/ut_list.h>
#include <string.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern void* lbl_805A0310;
extern char lbl_8059E480[3];
extern char lbl_8059E484[3];
extern char lbl_8059E540[6];
extern char lbl_8059E548[6];
extern char lbl_8059E550[6];
extern char lbl_8045CB40[];
extern char lbl_8045CCC0[];
void fn_800B6C38(void* out, void* src, const char* name);
void fn_800FFE6C(void* self, int, int, int, void*, void*);
void fn_800C1D2C();
void __destroy_arr(void*, void*, int, int);
void __dl__FPv(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
}

extern utList lbl_8049E560;

struct Name {
    char s[65];
};

class Object_vptr_0 {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(void*, void*);
    virtual void slot12(void*);
    virtual void slot13(void*);
};

struct Obj5C_base { char pad[0x5c]; };
class Obj5C : public Obj5C_base {
public:
    virtual void slot0(int);
};

struct Class_8045CB48_base { char pad[0x14]; };
class Class_8045CB48 : public Class_8045CB48_base {
public:
    virtual void fn_80100FB4();
    virtual void* fn_80101370();
};

struct SelfNode {
    utListNode* m_next;
    utListNode* m_prev;
    utList* m_list;
};

extern "C" void* fn_80100FB4(char* self, int arg1) {
    if (self != 0) {
        *(void**)(self + 0x14) = (void*)lbl_8045CB40;
        MuObject* obj;
        char* g = (char*)lbl_805A0310;
        if (g != 0) {
            void* r4 = ((Class_8045CB48*)self)->fn_80101370();
            char sp20[0xC];
            fn_800B6C38(sp20, r4, lbl_8059E540);
            if (*(int*)(self + 0x40) == 4) {
                int commonArg = *(int*)(self + 0x44);
                char sp14[0xC];
                fn_800B6C38(sp14, *(void**)(g + 0x280), lbl_8059E548);
                void* nw = __nw__FUlQ25Heaps8HeapType(0x40, 0x2A);
                if (nw != 0) {
                    fn_800FFE6C(nw, 7, commonArg, 0, sp20, sp14);
                }
            } else {
                int commonArg;
                int b;
                b = *(int*)(self + 0x48);
                commonArg = *(int*)(self + 0x44);
                char sp8[0xC];
                fn_800B6C38(sp8, *(void**)(g + 0x280), lbl_8059E550);
                void* nw = __nw__FUlQ25Heaps8HeapType(0x40, 0x2A);
                if (nw != 0) {
                    fn_800FFE6C(nw, 8, commonArg, b, sp20, sp8);
                }
                Object_vptr_0* p27C = *(Object_vptr_0**)(g + 0x27C);
                void* p2AC = *(void**)(g + 0x2AC);
                p27C->slot13(p2AC);
                p27C = *(Object_vptr_0**)(g + 0x27C);
                p27C->slot11(*(void**)((char*)p27C + 0xe4), *(void**)(g + 0x2AC));

                obj = *(MuObject**)(g + 0x2A4);
                char* mdl = *(char**)((char*)obj + 8);
                int off = *(int*)(mdl + 0x3c);
                const char* src = off ? mdl + off : 0;
                Name n4;
                Name n3;
                Name n2;
                Name n1;
                n1.s[0] = 0;
                strcat(n1.s, src);
                n2 = n1;
                strcat(n2.s, lbl_8059E484);
                n3 = n2;
                sprintf(n3.s + strlen(n3.s), lbl_8059E480, 0);
                n4 = n3;
                obj->changeNodeAnimNIf(n4.s);

                Object_vptr_0* p2AC2 = *(Object_vptr_0**)(g + 0x2AC);
                p2AC2->slot13(*(void**)((char*)*(void**)(g + 0x31C) + 0x10));

                int i = 0;
                char* cur = g;
                for (; i < *(int*)(g + 0x290); i++) {
                    Object_vptr_0* pp = *(Object_vptr_0**)(g + 0x2AC);
                    pp->slot13(*(void**)((char*)*(void**)(cur + 0x294) + 0x10));
                    cur += 4;
                }
            }
        }
        if (self + 0x4c != 0) {
            Obj5C* o = *(Obj5C**)(self + 0x4c);
            if (o != 0) {
                o->slot0(1);
            }
        }
        if (self + 0x18 != 0) {
            if (self + 0x3c != 0) {
                void* o = *(void**)(self + 0x3c);
                if (o != 0) {
                    Destroy__Q34nw4r3g3d6G3dObjFv(o);
                }
                *(void**)(self + 0x3c) = 0;
            }
            if (self + 0x38 != 0) {
                Object_vptr_0* o = *(Object_vptr_0**)(self + 0x38);
                if (o != 0) {
                    o->slot0(1);
                }
            }
            if (self + 0x34 != 0) {
                Obj5C* o = *(Obj5C**)(self + 0x34);
                if (o != 0) {
                    o->slot0(1);
                }
            }
            __destroy_arr(self + 0x24, (void*)fn_800C1D2C, 4, 4);
        }
        if (self != 0) {
            int* p = *(int**)(self + 0xc);
            *(void**)(self + 0x14) = (void*)lbl_8045CCC0;
            if (self != 0 && p != 0) {
                *(int*)(self + 0xc) = 0;
                *p = 0;
            }
            if (self != 0) {
                lbl_8049E560.removeExist((utListNode*)self);
                ((SelfNode*)self)->m_list = 0;
                if (self != 0) {
                    if (((SelfNode*)self)->m_list != 0) {
                        ((SelfNode*)self)->m_list->removeExist((utListNode*)self);
                        ((SelfNode*)self)->m_list = 0;
                    }
                }
            }
        }
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
