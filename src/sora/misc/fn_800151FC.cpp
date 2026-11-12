#include <types.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_file_io_handle.h>
#include <string.h>
#pragma force_active on
extern "C" void fn_80014028(void*); extern "C" void fn_8001429C(void*); extern u8 lbl_8059FF98;
#define F(p,t,o) (*(t*)((u8*)(p)+(o)))
struct ArchiveFlags { u8 complete:1; u8 pad:5; u8 flag:1; u8 tail:1; };
struct ArchiveResetFlags { u8 complete:1; u8 padding:2; u8 special:1; u8 low:4; };
struct FirstByte { unsigned int value:8; unsigned int rest:24; };
struct EntryFlags { u8 owned:1; u8 other:7; };
#define CLEAR(node,cursor,flags,index) cursor=node; flags=node+13; for(index=0; index<F(node,u16,2); flags+=16,cursor+=16,index++){ if((*flags>>7)&1){ gfHeapManager::free(F(cursor,void*,16)); F(cursor,void*,16)=0; ((EntryFlags*)flags)->owned=0; } }
extern "C" void fn_800151FC(u8* self,const char* path,int heap,int cached,u32 unk5,int heap2) {
u32 index3; u8* flags3; u8* cursor3; u8* flags2; u8* cursor2; u32 index2; u8* flags1; u8* cursor1; u32 index1; u8* flags; u8* cursor; u32 index; u8* node; u8* child1; u8* child2; u8* child3;
void* heapPtr=gfHeapManager::getHeap((Heaps::HeapType)heap); void* heap2Ptr=0;
if(unk5==1) heap2Ptr=gfHeapManager::getHeap((Heaps::HeapType)heap2);
((ArchiveFlags*)(self+9))->complete=0; ((FirstByte*)(self+8))->value=1;
if(F(self,void*,0x14)==0) F(self,void*,0x14)=heapPtr;
F(self,void*,0x18)=heap2Ptr; ((ArchiveFlags*)(self+9))->flag=unk5;
strncpy((char*)self+0x28,path,0x40);
if(lbl_8059FF98) ((gfFileIOHandle*)(self+0x6c))->read(path,(const void*)heapPtr,0);
else {
if(F(self,void*,0x20)){if((self[9]>>3)&1) fn_8001429C(self); if((self[9]>>6)&1) gfHeapManager::free(F(self,void*,0x20)); F(self,void*,0x20)=0;}
if(F(self,void*,0x1c)){gfHeapManager::free(F(self,void*,0x1c));F(self,void*,0x1c)=0;}
else {node=F(self,u8*,0x68); if(node){CLEAR(node,cursor,flags,index) child1=F(node,u8*,4); if(child1){CLEAR(child1,cursor1,flags1,index1) child2=F(child1,u8*,4); if(child2){CLEAR(child2,cursor2,flags2,index2) child3=F(child2,u8*,4); if(child3){CLEAR(child3,cursor3,flags3,index3) if(F(child3,void*,4)) fn_80014028(F(child3,void*,4)); gfHeapManager::free(child3);} gfHeapManager::free(child2);} gfHeapManager::free(child1);} gfHeapManager::free(node);}}
F(self,void*,0x68)=0; ((ArchiveResetFlags*)(self+9))->special=0; ((ArchiveResetFlags*)(self+9))->complete=0;
((gfFileIOHandle*)(self+0x6c))->setNotify(self+0x74);
if(cached) ((gfFileIOHandle*)(self+0x6c))->readRequestCached(path,(const void*)heapPtr,0,0); else ((gfFileIOHandle*)(self+0x6c))->readRequest(path,(const void*)heapPtr,0,0);
}
self[9]|=0x40;
}