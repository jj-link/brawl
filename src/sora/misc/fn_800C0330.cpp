#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <ty/ty_fig_listmng.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on
class MenuObject { char pad[0x5c]; public: virtual void method(int); };
extern "C" {
extern char lbl_80456F5C[];
void fn_800AD87C(void*, int);
void fn_800B8A0C(void*, int);
void fn_800C02D8(void*, int);
void __destroy_arr(void*, void (*)(void*, int), int, int);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void* fn_800C0330(unsigned char* self, int flag) {
 if (self) {
  *(void**)(self + 0x3c) = lbl_80456F5C;
  if (!self[0x2b4]) {
   tyFigListDataManager* p = *(tyFigListDataManager**)(self + 0x228);
   if (p) delete p;
  }
  ((gfFileIOHandle*)(self + 0x22c))->cancelRequest();
  if (*(void**)(self + 0x230)) gfHeapManager::free(*(void**)(self + 0x230));
  int n;
  gfFileIOHandle* handle = (gfFileIOHandle*)(self + 0x234);
  unsigned char* cursor = self;
  for (int i = 0; i < 16; ++i, handle = (gfFileIOHandle*)((char*)handle + 8), cursor += 8) {
   handle->cancelRequest();
   if (*(void**)(cursor + 0x238)) gfHeapManager::free(*(void**)(cursor + 0x238));
  }
  if (*(void**)(self + 0x2b8)) fn_800AD87C(*(void**)(self + 0x2b8), 1);
  ((gfFileIOHandle*)(self + 0x2bc))->cancelRequest();
  if (*(void**)(self + 0x2c0)) gfHeapManager::free(*(void**)(self + 0x2c0));
  cursor = self + 0x2c4;
  handle = (gfFileIOHandle*)self;
  for (int j = 0; j < 16; ++j, cursor += 8, handle = (gfFileIOHandle*)((char*)handle + 8)) {
   ((gfFileIOHandle*)cursor)->cancelRequest();
   if (*(void**)((char*)handle + 0x2c8)) gfHeapManager::free(*(void**)((char*)handle + 0x2c8));
  }
  ((gfFileIOHandle*)(self + 0x344))->cancelRequest();
  if (*(void**)(self + 0x348)) gfHeapManager::free(*(void**)(self + 0x348));
  cursor = self;
  handle = (gfFileIOHandle*)(self + 0x34c);
  for (int k = 0; k < 16; ++k, handle = (gfFileIOHandle*)((char*)handle + 8), cursor += 8) {
   handle->cancelRequest();
   if (*(void**)(cursor + 0x350)) gfHeapManager::free(*(void**)(cursor + 0x350));
  }
  if (*(void**)(self + 0x5c)) fn_800B8A0C(*(void**)(self + 0x5c), 1);
  nw4r::g3d::G3dObj* obj = *(nw4r::g3d::G3dObj**)(self + 0x54);
  if (obj) obj->Destroy();
  cursor = self;
  for (n = 0; n < 5; ++n, cursor += 4) {
   MenuObject* entry = *(MenuObject**)(cursor + 0x40);
   if (entry) { if (entry) entry->method(1); }
  }
  __destroy_arr(self + 0x34c, fn_800C02D8, 8, 16);
  __dt__14gfFileIOHandleFv(self + 0x344, -1);
  __destroy_arr(self + 0x2c4, fn_800C02D8, 8, 16);
  __dt__14gfFileIOHandleFv(self + 0x2bc, -1);
  __destroy_arr(self + 0x234, fn_800C02D8, 8, 16);
  __dt__14gfFileIOHandleFv(self + 0x22c, -1);
  __dt__6gfTaskFv(self, 0);
  if (flag > 0) __dl__FPv(self);
 }
 return self;
}
}