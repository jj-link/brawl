#pragma force_active on
#include <cm/cm_controller_ai.h>
extern "C" {
extern char lbl_68_data_208[];
void __dl__FPv(void*);
void __dla__FPv(void*);
void fn_27_239F6C(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__9gfArchiveFv(void*, int);
void __dt__7stMeleeFv(void*, int);

void* fn_68_350(void* self, int flag) {
    if (self) {
        char* p = (char*)self;
        *(void**)(p + 0x3c) = lbl_68_data_208;
        cmAIController* ai = g_cmAIController;
        if (ai) {
            *(unsigned int*)ai->_0x8 &= 0x00ffffff;
        }
        void* a = *(void**)(p + 0x388);
        if (a) __dl__FPv(a);
        void* b = *(void**)(p + 0x38c);
        if (b) __dl__FPv(b);
        void* c = *(void**)(p + 0x390);
        if (c) __dl__FPv(c);
        void* d = *(void**)(p + 0x394);
        if (d) __dl__FPv(d);
        void* e = *(void**)(p + 0x3ac);
        if (e) __dl__FPv(e);
        fn_27_239F6C(p + 0x218);
        fn_27_239F6C(p + 0x228);
        fn_27_239F6C(p + 0x238);
        fn_27_239F6C(p + 0x248);
        fn_27_239F6C(p + 0x258);
        fn_27_239F6C(p + 0x268);
        fn_27_239F6C(p + 0x278);
        fn_27_239F6C(p + 0x288);
        void* block = *(void**)(p + 0x428);
        if (block) {
            if (block) __dla__FPv((char*)block - 0x10);
            *(void**)(p + 0x428) = 0;
        }
        releaseArchive__15stCommonGimmickFv(self);
        __dt__9gfArchiveFv(p + 0x5ac, -1);
        __dt__9gfArchiveFv(p + 0x52c, -1);
        __dt__9gfArchiveFv(p + 0x4ac, -1);
        __dt__9gfArchiveFv(p + 0x42c, -1);
        __dt__7stMeleeFv(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
}