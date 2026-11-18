#include <mu/mu_msg.h>
#include <mu/menu.h>
#include <cm/cm_camera_controller.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on
inline void clearWords(int* p, int* e) { do { *p=0; ++p; } while (p<e); }
extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void fn_2_3BC(void*);
void __dt__14gfFileIOHandleFv(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* fn_800B08A8(int);
void* fn_800AFB94(const char*, int, const char*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_800AD808(void*, int);
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, HeapType, unsigned long);
extern const char lbl_2_data_1608[], lbl_2_data_1618[];
extern char lbl_2_data_18E8[];
extern const char* lbl_2_data_16C8[];
extern void* lbl_2_bss_40;
void* __ct__14tySealListTaskFv(void* self) {
    const char** files;
    char* b=(char*)self;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self,lbl_2_data_1608,0x12,0xe,6,true);
    *(int*)(b+0x44)=0; *(void**)(b+0x3c)=lbl_2_data_18E8;
    *(int*)(b+0x48)=0; *(int*)(b+0x58)=0; b[0x5c]=0;
    fn_800B96E8(b+0x60,0xff);
    b[0x5164]=0; *(int*)(b+0x52d4)=0; *(int*)(b+0x52d8)=0;
    clearWords((int*)(b+0x52d8),(int*)(b+0x5358));
    *(int*)(b+0x5358)=0;
    __construct_array(b+0x5364,fn_2_3BC,__dt__14gfFileIOHandleFv,4,4);
    __construct_array(b+0x5394,fn_2_3BC,__dt__14gfFileIOHandleFv,4,32);
    b[0x5414]=0; b[0x2c]&=~2; *(int*)(b+0x31f4)=0;
    char* q=b;
    for(int i=0;i<25;i++){
        *(int*)(q+0x4194)=0;
        *(int*)(q+0x4198)=0;
        *(int*)(q+0x419c)=0;
        *(int*)(q+0x41a0)=0;
        *(int*)(q+0x41a4)=0;
        *(int*)(q+0x41a8)=0;
        *(int*)(q+0x41ac)=0;
        *(int*)(q+0x41b0)=0;
        *(int*)(q+0x41b4)=0;
        *(int*)(q+0x41b8)=0;
        *(int*)(q+0x41bc)=0;
        *(int*)(q+0x41c0)=0;
        *(int*)(q+0x41c4)=0;
        *(int*)(q+0x41c8)=0;
        *(int*)(q+0x41cc)=0;
        *(int*)(q+0x41d0)=0;
        *(int*)(q+0x41d4)=0;
        *(int*)(q+0x41d8)=0;
        *(int*)(q+0x41dc)=0;
        *(int*)(q+0x41e0)=0;
        *(int*)(q+0x41e4)=0;
        *(int*)(q+0x41e8)=0;
        *(int*)(q+0x41ec)=0;
        *(int*)(q+0x41f0)=0;
        *(int*)(q+0x41f4)=0;
        *(int*)(q+0x41f8)=0;
        *(int*)(q+0x41fc)=0;
        *(int*)(q+0x4200)=0;
        *(int*)(q+0x4204)=0;
        *(int*)(q+0x4208)=0;
        *(int*)(q+0x420c)=0;
        *(int*)(q+0x4210)=0;
        *(int*)(q+0x4214)=0;
        *(int*)(q+0x4218)=0;
        *(int*)(q+0x421c)=0;
        *(int*)(q+0x4220)=0;
        *(int*)(q+0x4224)=0;
        *(int*)(q+0x4228)=0;
        *(int*)(q+0x422c)=0;
        *(int*)(q+0x4230)=0;
        q+=0xa0;
    }
    char* p=(char*)fn_800B08A8(0x2a);
    *(void**)(b+0x52c4)=p; *(void**)(p+0x40)=b+0x5168; *(int*)(p+0x44)=0x55;
    *(void**)(b+0x40)=fn_800AFB94(lbl_2_data_1608,0x55,lbl_2_data_1618);
    void* obj=__nw__FUlQ25Heaps8HeapType(0x3eb4,0x2a);
    if(obj) obj=fn_800AD808(obj,1);
    *(void**)(b+0x4c)=obj;
    {
        char* base=b; int count=0;
        while(count<80){
            *(int*)(base+0x5168)=0; count+=40;
            *(int*)(base+0x516c)=0;
            *(int*)(base+0x5170)=0;
            *(int*)(base+0x5174)=0;
            *(int*)(base+0x5178)=0;
            *(int*)(base+0x517c)=0;
            *(int*)(base+0x5180)=0;
            *(int*)(base+0x5184)=0;
            *(int*)(base+0x5188)=0;
            *(int*)(base+0x518c)=0;
            *(int*)(base+0x5190)=0;
            *(int*)(base+0x5194)=0;
            *(int*)(base+0x5198)=0;
            *(int*)(base+0x519c)=0;
            *(int*)(base+0x51a0)=0;
            *(int*)(base+0x51a4)=0;
            *(int*)(base+0x51a8)=0;
            *(int*)(base+0x51ac)=0;
            *(int*)(base+0x51b0)=0;
            *(int*)(base+0x51b4)=0;
            *(int*)(base+0x51b8)=0;
            *(int*)(base+0x51bc)=0;
            *(int*)(base+0x51c0)=0;
            *(int*)(base+0x51c4)=0;
            *(int*)(base+0x51c8)=0;
            *(int*)(base+0x51cc)=0;
            *(int*)(base+0x51d0)=0;
            *(int*)(base+0x51d4)=0;
            *(int*)(base+0x51d8)=0;
            *(int*)(base+0x51dc)=0;
            *(int*)(base+0x51e0)=0;
            *(int*)(base+0x51e4)=0;
            *(int*)(base+0x51e8)=0;
            *(int*)(base+0x51ec)=0;
            *(int*)(base+0x51f0)=0;
            *(int*)(base+0x51f4)=0;
            *(int*)(base+0x51f8)=0;
            *(int*)(base+0x51fc)=0;
            *(int*)(base+0x5200)=0;
            *(int*)(base+0x5204)=0;
            base+=0xa0;
        }
        int* tail=(int*)b+count;
        files=lbl_2_data_16C8;
        tail[0x145a]=0;
        tail[0x145b]=0;
        tail[0x145c]=0;
        tail[0x145d]=0;
        tail[0x145e]=0;
    }
    *(int*)(b+0x52bc)=0; *(int*)(b+0x52c0)=0; *(int*)(b+0x52d4)=0;
    *(int*)(b+0x5358)=0; *(int*)(b+0x52d8)=0;
    for(int i=0;i<31;i++) ((int*)(b+0x52dc))[i]=0;
    for(int i=0;i<32;i++) b[0x5374+i]=1;
    for(int i=0;i<6;i++) b[0x535c+i]=0;
    const char* names[4]={files[0],files[1],files[2],files[3]};
    unsigned int index=0; const char** name=names; int offset=0;
    do{
        ((gfFileIOHandle*)(b+0x5364+offset))->readRequest(*name,(HeapType)0x2b,0,0);
        ++name; ++index; offset+=4;
    }while(index<4);
    muMenu::loadMenuSound();
    MuMsg* msg=create__5MuMsgFUlQ25Heaps8HeapTypeUl(1,(HeapType)0x2a,0x2b);
    *(MuMsg**)(b+0x52c8)=msg; msg->allocMsgBuf(0x100,10);
    msg=create__5MuMsgFUlQ25Heaps8HeapTypeUl(2,(HeapType)0x2a,0x2b);
    *(MuMsg**)(b+0x52d0)=msg; msg->allocMsgBuf(0x80,3);
    fn_800B96E8(b+0x60,0xf0);
    CameraController::getInstance()->changeInput(CameraController::MenuFixed);
    lbl_2_bss_40=gfHeapManager::alloc((HeapType)0x2a,0x6400);
    return self;
}
}