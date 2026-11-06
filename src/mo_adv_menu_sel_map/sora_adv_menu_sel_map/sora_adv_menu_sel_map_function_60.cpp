#include <gf/gf_task.h>
#include <gf/gf_archive.h>
#include <mu/menu.h>
#include <cstring>
#pragma force_active on
extern "C" {
extern char lbl_31_data_0[];
extern char lbl_31_data_10[];
extern char lbl_31_data_26C[];
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void* __ct__9gfArchiveFv(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_31_2F0(void*);
void fn_31_324(void*);
void fn_1_3D44(void*, int, const char*, gfArchive*, int);
}
struct Array { char pad[0x1c4]; int values[178]; };
struct Loader { unsigned int fields[7]; bool a:1; bool b:1; bool c:1; unsigned char rest:5; };
#define W(o) (*(int*)(self+(o)))
#define B(o) (*(unsigned char*)(self+(o)))
extern "C" void* fn_31_60(char* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_31_data_0, 8, 15, 8, true);
    *(void**)(self+0x3c)=lbl_31_data_26C;
    W(0x40)=0; W(0x44)=0; W(0x48)=0; W(0x4c)=5;
    B(0x59)=1; B(0x5a)=0; W(0x5c)=0; W(0x60)=0;
    __construct_array(self+0x64,fn_31_2F0,fn_31_324,0xa8,2);
    W(0x1bc)=0; W(0x1c0)=0; W(0x4a0)=0; W(0x4a4)=0; W(0x4a8)=4;
    W(0x4b0)=0; W(0x4b4)=0; B(0x4c8)=0;
    W(0x5d4)=0; W(0x5d8)=0; W(0x5dc)=0; W(0x5e0)=0;
    B(0x5e4)=0; B(0x5e5)=0; B(0x5e6)=0; W(0x5e8)=0;
    W(0x494)=0; W(0x498)=0; W(0x49c)=0;
    for (int i=0; i<178; ++i) ((Array*)self)->values[i]=0;
    W(0x48c)=0; W(0x490)=0;
    memset(self+0x4c9,0,0x80); memset(self+0x549,0,0x80);
    int mode=W(0x40);
    W(0x5cc)=0; W(0x5d0)=0; W(0x50)=0; W(0x54)=0;
    bool special;
    if (mode==2) goto yes;
    if (mode==3) goto yes;
    if (mode==4) goto yes;
    if (mode==8) goto yes;
    if (mode==9) goto yes;
    if ((unsigned)(mode-5)>1) goto no;
    yes: special=true; goto done;
    no: special=false;
    done:
    if (special) { W(0x40)=0; W(0x1bc)=10; }
    B(0x4b8)=0; B(0x4b9)=0; W(0x4bc)=-1;
    gfArchive* arc=(gfArchive*)__nw__FUlQ25Heaps8HeapType(0x80,0x2b);
    if (arc) arc=(gfArchive*)__ct__9gfArchiveFv(arc);
    *(gfArchive**)(self+0x5d4)=arc;
    Loader* obj=(Loader*)__nw__FUlQ25Heaps8HeapType(0x20,0x2b);
    if (obj) {
      obj->fields[0]=0; obj->fields[1]=0; obj->fields[2]=0; obj->fields[3]=0; obj->fields[4]=0;
      obj->a=false; obj->b=false; obj->fields[6]=0; obj->fields[5]=0xff; obj->c=false;
    }
    *(Loader**)(self+0x5d8)=obj;
    fn_1_3D44(obj,0x2b,lbl_31_data_10,*(gfArchive**)(self+0x5d4),0);
    muMenu::loadMenuSound();
    return self;
}