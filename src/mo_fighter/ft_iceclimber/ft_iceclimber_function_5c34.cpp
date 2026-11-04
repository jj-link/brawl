#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_105_3674(void*, short);
void* fn_105_36B4(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_105_3814(void*, short);
void* fn_105_3880(void*, short);
void* fn_105_390C(void*, short);
void* fn_105_3998(void*, short);
void* fn_105_218C(void*, short);
void* fn_105_2228(void*, short);
void* fn_105_2268(void*, short);
void* fn_27_C7770(void*, short);
void* fn_105_3A80(void*, short);
void* fn_105_3ADC(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_10424(void*, short);
void* fn_105_3B38(void*, short);
void* fn_105_3BC4(void*, short);
void* fn_105_3CC0(void*, short);
void* fn_105_3EA0(void*, short);
void* fn_105_3F78(void*, short);
void* fn_27_1A4980(void*, short);
void* fn_105_3FD8(void*, short);
void* fn_105_4100(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_105_4160(void*, short);
void* fn_105_4294(void*, short);
void* fn_105_42F0(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_199E3C(void*, short);
void* fn_105_43B8(void*, short);
void* fn_105_4418(void*, short);
void* fn_105_4478(void*, short);
void* fn_105_44D4(void*, short);
void* fn_105_4558(void*, short);
void* fn_105_4624(void*, short);
void* fn_105_4680(void*, short);
void* fn_105_46F4(void*, short);
void* fn_105_47F4(void*, short);
void* fn_105_4860(void*, short);
void* fn_105_4918(void*, short);
void* fn_105_4958(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_105_49B4(void*, short);
void* fn_27_1D81C8(void*, short);
}
extern "C" void* fn_105_5C34(void* object, short deleting) {
 if (object != 0) {
  unsigned char* p = static_cast<unsigned char*>(object);
  if (p + 0x20E0 != 0) {
   if (p + 0x20E0 != 0) fn_105_3674(p + 0x20E0, 0);
  }
  if (object != 0) {
   fn_105_36B4(p + 0x2098, -1);
   fn_27_1DBB60(p + 0x2060, -1);
   if (p + 0xCC != 0) {
    if (p + 0x1AB0 != 0) {
     fn_105_3814(p + 0x1F60, -1);
     fn_105_3880(p + 0x1E34, -1);
     fn_105_390C(p + 0x1D08, -1);
     fn_105_3998(p + 0x1BDC, -1);
     if (p + 0x1AB0 != 0) {
      fn_105_218C(p + 0x1B8C, -1);
      fn_105_2228(p + 0x1B70, -1);
      fn_105_2268(p + 0x1AC4, -1);
      if (p + 0x1AB0 != 0) fn_27_C7770(p + 0x1AB0, -1);
     }
    }
    if (p + 0xCC != 0) {
     fn_105_3A80(p + 0x1A6C, -1);
     fn_105_3ADC(p + 0x1A54, -1);
     if (p + 0x18FC != 0) fn_27_BED74(p + 0x18FC, -1);
     if (p + 0x18AC != 0) fn_27_10424(p + 0x18B0, -1);
     fn_105_3B38(p + 0x1718, -1);
     fn_105_3BC4(p + 0x16B8, -1);
     fn_105_3CC0(p + 0x1604, -1);
     if (p + 0x1434 != 0) {
      fn_105_3EA0(p + 0x1554, -1);
      fn_105_3F78(p + 0x1540, -1);
      if (p + 0x1520 != 0) fn_27_1A4980(p + 0x1520, -1);
      fn_105_3FD8(p + 0x147C, -1);
      fn_105_4100(p + 0x1444, -1);
      fn_27_C74E8(p + 0x1434, -1);
     }
     fn_105_4160(p + 0x1390, -1);
     fn_105_4294(p + 0x135C, -1);
     fn_105_42F0(p + 0x1344, -1);
     if (p + 0x11AC != 0) {
      fn_27_6A3D8(p + 0x12F0, -1);
      fn_27_199E3C(p + 0x11AC, -1);
     }
     fn_105_43B8(p + 0x1144, -1);
     fn_105_4418(p + 0x1138, -1);
     fn_105_4478(p + 0x1110, -1);
     fn_105_44D4(p + 0xF40, -1);
     fn_105_4558(p + 0xEDC, -1);
     fn_105_4624(p + 0xEA0, -1);
     fn_105_4680(p + 0xDE8, -1);
     fn_105_46F4(p + 0xBDC, -1);
     fn_105_47F4(p + 0x9FC, -1);
     fn_105_4860(p + 0x9CC, -1);
     fn_105_4918(p + 0x9BC, -1);
     fn_105_4958(p + 0x9A4, -1);
     __dt__16soModuleAccesserFv(p + 0x8C4, -1);
     fn_105_49B4(p + 0xCC, -1);
    }
   }
   fn_27_1D81C8(object, 0);
  }
  if (deleting > 0) operator delete(object);
 }
 return object;
}