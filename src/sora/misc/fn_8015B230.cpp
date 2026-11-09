#pragma force_active on
struct Slot { float f0; int id; int data; float f1; };
struct Record { Slot slots[40]; };
struct Result { char pad[0x24]; int data; char pad28[4]; int id; float f30; float f34; };
struct GameGlobal { char pad[0x30]; void* data; };
extern "C" float lbl_805A2BA8;
extern "C" GameGlobal* g_GameGlobal;
extern "C" Result* fn_800AE578(void*, int);
extern "C" void fn_800AD87C(void*, int);
inline int find(int id, int i, Slot* p, int count) {
 for (; i<count; ++p, ++i) {
  if(p->id == -1) return i;
  if(id == p->id) return i;
 }
 return 0;
}
extern "C" void fn_8015B230(Record* self) {
 float sentinel=lbl_805A2BA8;
 int invalid=-1;
 unsigned int row=0;
 Record* current=self;
 do {
 Slot* p=current->slots;
 for(int batch=0;batch<5;++batch,p+=8) {
 p[0].id=invalid;p[0].f1=sentinel;p[1].f0=sentinel;
 p[1].id=invalid;p[1].f1=sentinel;p[2].f0=sentinel;
 p[2].id=invalid;p[2].f1=sentinel;p[3].f0=sentinel;
 p[3].id=invalid;p[3].f1=sentinel;p[4].f0=sentinel;
 p[4].id=invalid;p[4].f1=sentinel;p[5].f0=sentinel;
 p[5].id=invalid;p[5].f1=sentinel;p[6].f0=sentinel;
 p[6].id=invalid;p[6].f1=sentinel;p[7].f0=sentinel;
 p[7].id=invalid;p[7].f1=sentinel;p[8].f0=sentinel;
 }
 ++row;++current;
 }while(row<35U);
 unsigned char* page=(unsigned char*)g_GameGlobal->data+0x6F8;
 Record* rec=self;
 unsigned char* entry;
 int outer;
 for(outer=0;outer<35;++outer,page+=0x1E0,++rec) {
 entry=page;
 for(int i=0;i<40;++i,entry+=12) {
 int id=*(int*)entry;
 if(id<=0) break;
 Result* result=fn_800AE578(*(void**)self,id);
 int index=find(result->id,0,rec->slots,40);
 Slot* slot=&rec->slots[index];
 slot->id=*(unsigned int*)((char*)result+0x2C);
 if(slot->f1<result->f30) {
 slot->f1=result->f30;
 slot[1].f0=result->f34;
 slot->data=result->data;
 }
 }
 }
 fn_800AD87C(*(void**)self,1);
 *(void**)self=0;
}