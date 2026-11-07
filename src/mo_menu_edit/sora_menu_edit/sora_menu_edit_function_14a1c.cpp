#include <mu/mu_msg.h>
#include <gf/gf_file_io_handle.h>
#include <string.h>
#pragma force_active on
extern "C" void fn_8006BCA8(char*, const void*);
struct Entry { char pad[0x10]; unsigned long index; };
extern "C" Entry* fn_800791FC(void*, unsigned int);
extern "C" void* lbl_805A01D8;
struct Context { char pad[0x194]; void* field194; char pad2[0x1c7c-0x198]; MuMsg* msg; char pad3[0x1d34-0x1c80]; gfFileIOHandle handle; };
struct Base { char pad[0x3c]; };
struct Self : Base {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17();
virtual void v18();
virtual void v19();
virtual void v20();
virtual void v21();
virtual void v22();
virtual void v23();
virtual void v24();
virtual void v25();
virtual void v26();
virtual void v27();
virtual void v28();
virtual void v29();
virtual void v30();
virtual void v31();
virtual void v32();
virtual void v33();
virtual void v34();
virtual void v35();
virtual void v36();
virtual void v37();
virtual void v38();
virtual void v39();
virtual void v40();
virtual void v41();
virtual void first(void*);
virtual void second(void*);
char pad2[0x1ac-0x40]; Context* context;
};
extern "C" void fn_5_14A1C(Self* self, char* arg) {
 char output1[0x4c]; char output2[0x54]; char converted1[0x44]; char converted2[0x54]; short name1[17]; short name2[21];
 self->second(self->context->field194);
 self->first(self->context->field194);
 char* p = arg + 0x54;
 memcpy(name1,p,0x20); name1[16]=0; output1[0]=0;
 fn_8006BCA8(converted1,name1); strcat(output1,converted1); self->context->msg->printf(0x11,output1);
 memcpy(name2,arg+0x28,0x28); name2[20]=0; output2[0]=0;
 fn_8006BCA8(converted2,name2); strcat(output2,converted2); self->context->msg->printf(0x12,output2);
 Entry* entry=fn_800791FC(lbl_805A01D8,*(unsigned short*)(p+0x20));
 void* buffer=self->context->handle.getBuffer();
 self->context->msg->printIndex(0x13,entry->index,buffer);
}