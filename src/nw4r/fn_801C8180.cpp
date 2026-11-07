#include <revolution/OS/OSMutex.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void* slot1(unsigned int);
 virtual void slot2();
 virtual int slot3(void*, unsigned int);
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual int slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual unsigned int slot14();
 virtual void slot15(); virtual void slot16(); virtual void slot17();
 virtual int slot18();
};
struct Context { OSMutex mutex; void* archive; char buffer[0x200]; Object_vptr_0* current; };
struct Info { int words[6]; };
extern "C" Object_vptr_0* fn_801C6E60(void*, int, void*, int);
extern "C" Object_vptr_0* fn_801C6F78(void*, int, void*, int);
extern "C" int fn_801C6C1C(void*, int, Info*);
extern "C" void* fn_801C8180(Context* ctx, int index, Object_vptr_0* allocator, void** out, unsigned int chunk) {
 OSLockMutex(&ctx->mutex);
 Object_vptr_0* file=fn_801C6E60(ctx->archive,index,ctx->buffer,0x200);
 if (!file) { if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0; }
 if (!file->slot18() || !file->slot9()) { if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0; }
 Object_vptr_0* file2;
 void* data=allocator->slot1(file->slot14());
 if (!data) { if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0; }
 ctx->current=file;
 if (!chunk) {
  if (file->slot3(data,file->slot14()) < 0) { ctx->current=0; if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0; }
 } else {
  char* dest=(char*)data;
  unsigned int left=file->slot14();
  while(left) {
   int n=file->slot3(dest, chunk > left ? left : chunk);
   if(n<0) {ctx->current=0; if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0;}
   if(left>(unsigned int)n) {left-=n; dest+=n;} else left=0;
  }
 }
 ctx->current=0;
 Info info;
 if(!fn_801C6C1C(ctx->archive,index,&info)) { if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0; }
 if(info.words[5]) {
  file2=fn_801C6F78(ctx->archive,index,ctx->buffer,0x200);
  if(!file2) { if(file2) file2->slot2(); if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0; }
  if(!file2->slot18() || !file2->slot9()) { if(file2) file2->slot2(); if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0; }
  void* data2=allocator->slot1(file2->slot14());
  if(!data2) { if(file2) file2->slot2(); if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0; }
  ctx->current=file2;
  if(!chunk) {
   if(file2->slot3(data2,file2->slot14())<0) {ctx->current=0; if(file2) file2->slot2(); if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0;}
  } else {
   char* dest=(char*)data2;
   unsigned int left=file2->slot14();
   while(left) {
    int n=file2->slot3(dest,chunk>left?left:chunk);
    if(n<0) {ctx->current=0;if(file2) file2->slot2(); if(file) file->slot2(); OSUnlockMutex(&ctx->mutex); return 0;}
    if(left>(unsigned int)n) {left-=n;dest+=n;} else left=0;
   }
  }
  ctx->current=0;
  if(out) *out=data2;
  if(file2) file2->slot2();
 } else if(out) *out=0;
 if(file) file->slot2();
 OSUnlockMutex(&ctx->mutex);
 return data;
}