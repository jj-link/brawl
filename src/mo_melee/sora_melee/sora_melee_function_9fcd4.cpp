#include <types.h>
#include <GX.h>
#include <ef/ef_screen.h>
#include <ef/ef_screen_handle.h>
#pragma force_active on
struct HandleGetter { virtual void slot0(); virtual efScreenHandle* get(); };
struct EntryGetter { virtual void slot0(); virtual u8* get(s32 index); };
struct ColorBuffer { GXColor color; int pad; };
struct Alpha { s8 value; };
extern f32 lbl_27_rodata_CB0;
extern f64 lbl_27_rodata_CB8;
extern "C" u32 isValid__14efScreenHandleCFv(const efScreenHandle*);
extern "C" void fn_8005E344(void*, Alpha, GXColor*, float);
extern "C" void fn_8005E3C8(efScreen*, Alpha, float);
extern "C" void fn_27_9FCD4(HandleGetter** arg0, s32 index, s32 amount, const GXColor* color, s32 width, s32 height) {
 GXColor source;
 if (index == -1) {
  GXColor fillBuffer;
  Alpha alpha;
  fillBuffer = *color;
  u32 result = g_efScreen->requestFill(lbl_27_rodata_CB0, width, height, &fillBuffer);
  alpha.value = (s8)(result >> 24);
  fn_8005E3C8(g_efScreen, alpha, (float)amount);
  return;
 }
 efScreenHandle* handle = (*arg0)->get();
 if (isValid__14efScreenHandleCFv(handle) == 1U) {
  source = *color;
  u8* entry = ((EntryGetter*)*arg0)->get(index);
  Alpha alpha = { (s8)*entry };
  GXColor copy = source;
  fn_8005E344(g_efScreen, alpha, &copy, (float)amount);
  return;
 }
 GXColor fillColor = *color;
 u8 alpha = (u8)(g_efScreen->requestFill((float)amount, width, height, &fillColor) >> 24);
 *(((EntryGetter*)*arg0)->get(index)) = alpha;
}