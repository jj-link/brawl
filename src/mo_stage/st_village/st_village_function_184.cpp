#pragma force_active on
extern "C" {

extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__7stMeleeFv(void*, int);
extern void __dl__FPv(void*);
extern unsigned char lbl_70_data_6E0[];

class UnkObj {
public:
    virtual void fn0(int arg);
};

void* fn_70_184(void* self, int deleteFlag) {
    if (self != 0) {
        UnkObj* ptr1 = reinterpret_cast<UnkObj*>(*(void**)((char*)self + 0x28C));
        *(void**)((char*)self + 0x3C) = lbl_70_data_6E0;
        if (ptr1 && ptr1) {
            ptr1->fn0(1);
        }
        UnkObj* ptr2 = reinterpret_cast<UnkObj*>(*(void**)((char*)self + 0x290));
        *(void**)((char*)self + 0x28C) = 0;
        if (ptr2 && ptr2) {
            ptr2->fn0(1);
        }
        *(void**)((char*)self + 0x290) = 0;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

}
