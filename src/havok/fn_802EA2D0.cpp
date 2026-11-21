#pragma force_active on
extern "C" void fn_80280148(void**, int, unsigned short);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(void*); };
struct MainObject { unsigned char pad0[0x38]; void** groups; int groupCount; unsigned char pad40[0x20]; Object_vptr_0** objects; int objectCount; };
struct Group { unsigned char pad0[0x40]; unsigned char* entriesA; int countA; unsigned char pad48[0x24]; unsigned char* entriesB; int countB; };
struct Array { unsigned char** data; int size; unsigned int capacity; bool isOwned() const { return (capacity & 0x80000000) == 0; } void dealloc() { fn_8027EABC(lbl_805A0EC8, data, capacity * 4, 0x15); } };
struct HBool { signed char v; HBool(bool b):v(b) {} operator bool() const { return v != 0; } };
static HBool is7(unsigned char* p) { return HBool(p[0xA8] == 7); }
static HBool equal_state(void** state) { char* s=(char*)*state; int* p=*(int**)s; return HBool(*p == -*(int*)(s+4)); }
extern "C" int fn_802EA2D0(MainObject* a, void** b) {
 int offset;
 int off;
 int i;
 Group* g;
 i=0; offset=0;
 while(i<a->groupCount) {
  g=(Group*)*(void**)((char*)a->groups+offset);
  int j=0; off=0;
  while(j<g->countA) {
   unsigned char* item=*(unsigned char**)(g->entriesA+off+4);
   unsigned char* data=item+*(int*)(item+16);
   if(!is7(data)) { fn_80280148(b,i,*(unsigned short*)(data+0x90)); if(equal_state(b)) return 0x01000000; }
   off+=8; ++j;
  }
  offset+=4; ++i;
 }
 {
 int i2=0, offset2=0, off2;
 Group* g2;
 while(i2<a->groupCount) {
  g2=(Group*)*(void**)((char*)a->groups+offset2);
  int j2=0; off2=0;
  while(j2<g2->countB) {
   unsigned char* entry=g2->entriesB+off2;
   unsigned char* first=*(unsigned char**)(entry+4);
   int valid = 0;
   if (!is7(first)) { if (!is7(*(unsigned char**)(entry+8))) valid = 1; }
   if(valid) { fn_80280148(b,*(unsigned short*)(first+0x90),*(unsigned short*)(*(unsigned char**)(entry+8)+0x90)); if(equal_state(b)) return 0x01000000; }
   off2+=0x24; ++j2;
  }
  offset2+=4; ++i2;
 }
 }
 unsigned char* local[11]; Array ar; ar.data=local; ar.size=0; ar.capacity=0x8000000A;
 int i3=0;
 while(i3<a->objectCount) {
  if(a->objects[i3]) {
   ar.size=0; a->objects[i3]->slot3(&ar);
   int n=0, found=-1;
   while(found==-1 && n<ar.size) { if(!is7(ar.data[n])) found=n; ++n; }
   while(n<ar.size) {
    unsigned char* candidate=ar.data[n];
    if(!is7(candidate)) {
     unsigned char* first=ar.data[found];
     fn_80280148(b,*(unsigned short*)(first+0x90),*(unsigned short*)(candidate+0x90));
     if(equal_state(b)) { if(ar.isOwned()) ar.dealloc(); return 0x01000000; }
    }
    ++n;
   }
  }
  ++i3;
 }
 if(ar.isOwned()) ar.dealloc();
 return ((*(int*)*(void**)*b == -*(int*)((char*)*b+4)) << 24);
}