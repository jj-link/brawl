#pragma force_active on

#include <gf/gf_archive.h>

extern "C" {

void __dla__FPv(void*);
void __dl__FPv(void*);
void __dt__9gfArchiveFv(void*, int);
void fn_8001AE1C(void*, char*);
int sprintf(char*, const char*, ...);
extern void* lbl_8059FFC8;
extern char lbl_8059DAE8;

struct ArchiveData {
    void* f00;
    void* f04;
    void* f08;
    int f0C;
    int f10;
    unsigned char f14;
};

void fn_80064284(ArchiveData* self, int flag) {
    void* archive = self->f00;
    if (archive != 0) {
        void* heap = lbl_8059FFC8;
        if (heap != 0) {
            void* result = ((gfArchive*)archive)->getData(Data_Type_Misc, 1, 0xFFFE);
            ((gfArchive*)self->f00)->getData(Data_Type_Misc, 2, 0xFFFE);
            if (result != 0) {
                char buf[16];
                sprintf(buf, &lbl_8059DAE8, self->f10);
                fn_8001AE1C(heap, buf);
            }
        }
        if (flag != 0) {
            self->f14 = 0xFF;
        }
    }

    void* ptr4 = self->f04;
    if (ptr4 != 0) {
        if (ptr4 != 0) {
            if (ptr4 != 0) {
                __dla__FPv((char*)ptr4 - 0x10);
            }
            self->f04 = 0;
        }
    }

    void* ptr8 = self->f08;
    if (ptr8 != 0) {
        __dl__FPv(ptr8);
        self->f08 = 0;
    }

    void* ptr0 = self->f00;
    if (ptr0 != 0) {
        __dt__9gfArchiveFv(ptr0, 1);
        self->f00 = 0;
    }
}

}