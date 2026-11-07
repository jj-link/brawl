#pragma force_active on
typedef unsigned char Byte;
typedef unsigned long Word;
class ModuleInterface {
public:
 virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
 virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
 virtual void slot28(); virtual void slot2C(); virtual void append(void*);
 virtual void slot34(); virtual void slot38(); virtual void initialize();
};
struct WorkHead { Word header[2]; };
class WorkInterface : public WorkHead {
public:
 virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
 virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
 virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
 virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
 virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
 virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
 virtual void slot68(); virtual void initialize();
};
extern "C" {
void fn_27_C74BC(void*, void*, int);
void fn_106_65AC(void*, void*, int, void*, int, void*, int);
void fn_27_19E930(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_D2898(void*, int);
void fn_27_1A1F78(void*, int);
void fn_27_1A1834(void*, int);
void fn_27_1A1C90(void*, int);
void fn_106_5A84(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A3A20(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern Byte lbl_106_data_0[];
}
extern "C" void* fn_106_6224(Byte* object, void* owner, void* resource, void* parameters) {
 fn_27_C74BC(object, resource, 0x112);
 Byte* work = object + 0x10;
 fn_106_65AC(work + 0xBC, work, 0x1A, work + 0x68, 0xE, work + 0xA0, 7);
 reinterpret_cast<WorkInterface*>(work + 0xBC)->initialize();
 Byte* modules = object + 0xF0;
 fn_27_19E930(modules, 0);
 Byte* entries = modules + 0x19C;
 fn_27_1A154C(entries, 0);
 fn_27_1A1E04(entries + 0x1C, 0);
 fn_27_1A1B1C(entries + 0x88, 0);
 fn_27_D2898(entries + 0xB4, 0);
 fn_27_1A1B1C(entries + 0xF0, 0);
 fn_27_1A154C(entries + 0x11C, 0);
 fn_27_1A154C(entries + 0x138, 0);
 fn_27_D2898(entries + 0x154, 0);
 fn_27_1A1E04(entries + 0x190, 0);
 fn_27_1A154C(entries + 0x1FC, 0);
 fn_27_1A1B1C(entries + 0x218, 0);
 fn_27_1A1F78(entries + 0x244, 0);
 fn_27_1A1B1C(entries + 0x2D0, 0);
 fn_27_1A154C(entries + 0x2FC, 0);
 fn_27_D2898(entries + 0x318, 0);
 fn_27_1A1834(entries + 0x354, 0);
 fn_27_1A154C(entries + 0x470, 0);
 fn_27_1A1B1C(entries + 0x48C, 0);
 fn_27_1A1E04(entries + 0x4B8, 0);
 fn_27_1A1C90(entries + 0x524, 0);
 fn_106_5A84(modules + 0x85C, modules);
 for (int i = 0; i < 20; ++i) {
  Word entry[5];
  fn_27_AB15C(entry,
   i == 0 ? modules + 0x6C0 :
   i == 1 ? modules + 0x654 :
   i == 2 ? modules + 0x628 :
   i == 3 ? modules + 0x60C :
   i == 4 ? modules + 0x4F0 :
   i == 5 ? modules + 0x4B4 :
   i == 6 ? modules + 0x498 :
   i == 7 ? modules + 0x46C :
   i == 8 ? modules + 0x3E0 :
   i == 9 ? modules + 0x3B4 :
   i == 10 ? modules + 0x398 :
   i == 11 ? modules + 0x32C :
   i == 12 ? modules + 0x2F0 :
   i == 13 ? modules + 0x2D4 :
   i == 14 ? modules + 0x2B8 :
   i == 15 ? modules + 0x28C :
   i == 16 ? modules + 0x250 :
   i == 17 ? modules + 0x224 :
   i == 18 ? modules + 0x1B8 :
   i == 19 ? modules + 0x19C : 0);
  reinterpret_cast<ModuleInterface*>(modules)->append(entry);
  fn_27_AB18C(entry, -1);
 }
 fn_27_1A3A20(object + 0x964, 0);
 *reinterpret_cast<Byte**>(object + 0xDF4) = object + 0xDF8;
 fn_27_1A29F0(object + 0xDF8, 1, lbl_106_data_0, 0);
 reinterpret_cast<ModuleInterface*>(object + 0xDF8)->initialize();
 fn_27_73930(object + 0xE08, owner, object, object + 0x964,
  object + 0xCC, object + 0x94C, object + 0xDF4, parameters, 0x121, 1);
 return object;
}