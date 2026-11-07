#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" void* fn_119_12550(void*, short);
extern "C" void* fn_119_124F4(void*, short);
extern "C" void* fn_119_12498(void*, short);
extern "C" void* fn_119_1243C(void*, short);
extern "C" void* fn_119_2E74(void*, short);
extern "C" void* fn_119_123B0(void*, short);
extern "C" void* fn_119_12350(void*, short);
extern "C" void* fn_119_122D8(void*, short);
extern "C" void* fn_119_12128(void*, short);
extern "C" void* fn_119_11ECC(void*, short);
extern "C" void* fn_119_45EC(void*, short);
extern "C" void* fn_119_11E10(void*, short);
extern "C" void* fn_119_11DA4(void*, short);
extern "C" void* fn_119_11D38(void*, short);
extern "C" void* fn_119_11C98(void*, short);
extern "C" void* fn_119_11C3C(void*, short);
extern "C" void* fn_119_11BB8(void*, short);
extern "C" void* fn_119_11AF4(void*, short);
extern "C" void* fn_119_4F84(void*, short);
extern "C" void* fn_119_504C(void*, short);
extern "C" void* fn_119_1197C(void*, short);
extern "C" void* fn_119_117DC(void*, short);
extern "C" void* fn_119_11764(void*, short);
extern "C" void* fn_119_116A8(void*, short);
extern "C" void* fn_119_566C(void*, short);
extern "C" void* fn_119_114E0(void*, short);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_119_125AC(void* object, short deleting) {
 if (object != 0) {
  unsigned char* p = static_cast<unsigned char*>(object);
  fn_119_12550(p + 0x1bbc, static_cast<short>(-1));
  fn_119_124F4(p + 0x1b7c, static_cast<short>(-1));
  fn_119_12498(p + 0x1b64, static_cast<short>(-1));
  fn_119_1243C(p + 0x1a0c, static_cast<short>(-1));
  fn_119_2E74(p + 0x19c0, static_cast<short>(-1));
  fn_119_123B0(p + 0x1828, static_cast<short>(-1));
  fn_119_12350(p + 0x17c8, static_cast<short>(-1));
  fn_119_122D8(p + 0x1714, static_cast<short>(-1));
  fn_119_12128(p + 0x152c, static_cast<short>(-1));
  fn_119_11ECC(p + 0x1488, static_cast<short>(-1));
  fn_119_45EC(p + 0x1454, static_cast<short>(-1));
  fn_119_11E10(p + 0x143c, static_cast<short>(-1));
  fn_119_11DA4(p + 0x12d8, static_cast<short>(-1));
  fn_119_11D38(p + 0x1270, static_cast<short>(-1));
  fn_119_11C98(p + 0x1264, static_cast<short>(-1));
  fn_119_11C3C(p + 0x123c, static_cast<short>(-1));
  fn_119_11BB8(p + 0xebc, static_cast<short>(-1));
  fn_119_11AF4(p + 0xe58, static_cast<short>(-1));
  fn_119_4F84(p + 0xe1c, static_cast<short>(-1));
  fn_119_504C(p + 0xd64, static_cast<short>(-1));
  fn_119_1197C(p + 0xb1c, static_cast<short>(-1));
  fn_119_117DC(p + 0x93c, static_cast<short>(-1));
  fn_119_11764(p + 0x90c, static_cast<short>(-1));
  fn_119_116A8(p + 0x8fc, static_cast<short>(-1));
  fn_119_566C(p + 0x8e4, static_cast<short>(-1));
  reinterpret_cast<soModuleAccesser*>(p + 0x804)->soModuleAccesser::~soModuleAccesser();
  fn_119_114E0(object, static_cast<short>(-1));
  if (deleting > 0) __dl__FPv(object);
 }
 return object;
}