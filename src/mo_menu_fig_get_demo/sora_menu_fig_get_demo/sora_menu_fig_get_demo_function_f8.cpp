#include <gf/gf_task.h>
#include <gf/gf_file_io_handle.h>
#include <types.h>
#pragma force_active on
extern "C" {
extern const char lbl_26_data_0[];
extern const char lbl_26_data_1C0[];
gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(gfTask*, const char*, gfTask::Category, int, int, bool);
void fn_26_5C8(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, int);
}
inline void clearWords(int* p, int* e) {
 do { *p=0; p++; } while(p<e);
}
struct DemoArrays {
 char pad[0x204];
 int first[100];
 char pad394[0x338];
 int second[204];
};
inline void clearFirst(DemoArrays* a) {
 for (int i=0;i<100;i++) a->first[i]=0;
}
inline void clearSecond(DemoArrays* a) {
 for (int i=0;i<204;i++) a->second[i]=0;
}
extern "C" DemoArrays* fn_26_F8(DemoArrays* self) {
 char* s = (char*)self;
 __ct__6gfTaskFPCcQ26gfTask8Categoryiib((gfTask*)self, lbl_26_data_0, (gfTask::Category)8, 15, 8, true);
 *(int*)(s+0x40)=0;
 *(const char**)(s+0x3c)=lbl_26_data_1C0;
 *(int*)(s+0x44)=0;
 *(int*)(s+0x48)=0;
 *(int*)(s+0x1dc)=0;
 *(int*)(s+0x1e4)=0;
 clearWords((int*)(s+0x394),(int*)(s+0x524));
 *(int*)(s+0x524)=0;
 *(int*)(s+0x528)=0;
 *(int*)(s+0x52c)=0;
 *(int*)(s+0x530)=0;
 clearWords((int*)(s+0x53c),(int*)(s+0x6cc));
 __construct_array(s+0x9fc,fn_26_5C8,__dt__14gfFileIOHandleFv,4,0x258);
 *(int*)(s+0x1360)=0;
 *(int*)(s+0x1364)=0;
 *(int*)(s+0x1368)=0;
 *(int*)(s+0x136c)=5;
 *(u8*)(s+0x1370)=0;
 *(int*)(s+0x1f4)=0;
 *(int*)(s+0x1f8)=0;
 *(int*)(s+0x1fc)=0;
 *(int*)(s+0x200)=0;
 for (int i=0;i<100;i++) self->first[i]=0;
 for(int i=0;i<204;i++) self->second[i]=0;
 *(int*)(s+0x1e8)=0;
 *(int*)(s+0x1ec)=0;
 *(int*)(s+0x1f0)=0;
 return self;
}
