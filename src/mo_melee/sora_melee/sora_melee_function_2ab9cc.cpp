#include <types.h>
#include <it/it_manager.h>
#pragma force_active on
struct ItemInfo { int kind; u32 variation; };
struct Archive { void* vtable; ItemInfo info; u32 dbId; char _10[2]; u8 loaded; ItemInfo getInfo() const { return info; } };
struct Param { u32 unk0; char _4[8]; char* elems; u32 num; };
class ArchiveList { public: virtual void v0(); virtual void v1(); virtual Archive*& at(int); virtual int size(); };
struct Manager { char pad[0x1170]; ArchiveList list; char pad2[0x32c]; u8 unk14a0; };
extern "C" int fn_27_2B2A9C(void*);
extern "C" int fn_27_2B2AF4(void*);
extern "C" u32 fn_27_2B2D44(void*, int);
extern "C" void* fn_27_2B2C80(void*, u32, int);
extern int lbl_27_data_71BF0[];
extern int lbl_27_data_737A0[];
extern "C" int fn_27_2AB9CC(void* arg0, const ItemInfo* arg1) {
 Manager* mgr=(Manager*)arg0; ItemInfo id=*arg1; int i=0; Archive* entry;
 for(;i<mgr->list.size();i++){Archive* e=mgr->list.at(i);int matchVar=0;int matchKind=0;
 if(e){if(id.kind==e->getInfo().kind)matchKind=1;}
 if(matchKind){ItemInfo t2=e->info;if(id.variation==t2.variation)matchVar=1;}
 if(matchVar){entry=e;goto found;}}
 entry=0;
found:
 if(!entry)return 0;if(!fn_27_2B2A9C(entry))return 0;if(entry->loaded)return 1;if(fn_27_2B2AF4(entry))return 1;
 u32 off; int* p4;
 for(u32 gen=0;gen<5;gen++){u32 count=fn_27_2B2D44(entry,gen);for(u32 j=0;j<count;j++){Param* p=(Param*)fn_27_2B2C80(entry,j,gen);if(!p)continue;if(p->unk0==0x2710&&!mgr->unk14a0)continue;u32 k=0;off=0;for(;k<p->num;off+=0x10,k++){char* el=p->elems+off;int kind=*(int*)el;if(kind==-1)break;switch(kind){case 0x7d1:kind=0x40;break;case 0x7d2:case 0x7d3:if(mgr->unk14a0){if(!((itManager*)arg0)->isCompItemKindArchive((itKind)0x3e,0x1388,true))return 0;}else{p4=lbl_27_data_737A0;for(u32 m=0;m<4;m++,p4++)if(!((itManager*)arg0)->isCompItemKindArchive((itKind)*p4,0x1388,true))return 0;}continue;case 0x7d4:case 0x7d5:continue;}int r0;if(kind==-3)r0=1;else if(kind<0||kind>=0xb2)r0=-1;else r0=lbl_27_data_71BF0[kind];switch(r0){case 2:case 3:case 4:case 6:case 7:continue;}if(kind==0x46){int var=*(int*)(el+4);if(var!=0x1388&&!((itManager*)arg0)->isCompItemKindArchive((itKind)kind,var,true))return 0;}else if(!((itManager*)arg0)->isCompItemKindArchive((itKind)kind,0x1388,true))return 0;}}}
 entry->loaded=1;return 1;
}