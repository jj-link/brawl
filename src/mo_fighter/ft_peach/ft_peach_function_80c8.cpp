#pragma force_active on
typedef unsigned char Byte;
typedef unsigned long Word;
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void fn_103_D378(); virtual void fn_103_D374(); virtual void fn_103_D370();
 virtual void slot7(); virtual void fn_103_D368(); virtual void fn_103_D360(); virtual void fn_103_D35C(void*);
};
struct WorkPrefix { Word header[2]; };
class Work : public WorkPrefix {
public:
 virtual void a00(); virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04();
 virtual void a05(); virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09();
 virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14();
 virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
 virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void reset();
};
class StatusVirtual {
public:
 virtual void a00(); virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04();
 virtual void a05(); virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09();
 virtual void a10(); virtual void a11(); virtual void a12(); virtual void initialize();
};
extern "C" {
void fn_27_C74BC(void*, void*, int);
void fn_103_8450(void*, void*, int, void*, int, void*, int);
void fn_27_19E930(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_D2898(void*, int);
void fn_27_D2A38(void*, int);
void fn_27_1A1F78(void*, int);
void fn_27_1A19A8(void*, int);
void fn_27_1A1C90(void*, int);
void fn_103_788C(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A3818(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern Byte lbl_103_data_0[];
}
extern "C" void* fn_103_80C8(Byte* object, void* owner, void* resource, void* parameters) {
 fn_27_C74BC(object, resource, 0x112);
 Byte* work = object + 0x10;
 fn_103_8450(work + 0x88, work, 0x12, work + 0x48, 0xe, work + 0x80, 2);
 reinterpret_cast<Work*>(work + 0x88)->reset();
 Byte* modules = object + 0xbc;
 fn_27_19E930(modules, 0);
 Byte* entries = modules + 0x19c;
 fn_27_1A154C(entries, 0);
 fn_27_1A1E04(entries + 0x1c, 0);
 fn_27_1A1B1C(entries + 0x88, 0);
 fn_27_D2898(entries + 0xb4, 0);
 fn_27_1A1B1C(entries + 0xf0, 0);
 fn_27_1A154C(entries + 0x11c, 0);
 fn_27_1A154C(entries + 0x138, 0);
 fn_27_D2A38(entries + 0x154, 0);
 fn_27_1A1E04(entries + 0x1a0, 0);
 fn_27_1A154C(entries + 0x20c, 0);
 fn_27_1A1B1C(entries + 0x228, 0);
 fn_27_1A1F78(entries + 0x254, 0);
 fn_27_1A1B1C(entries + 0x2e0, 0);
 fn_27_1A154C(entries + 0x30c, 0);
 fn_27_D2898(entries + 0x328, 0);
 fn_27_1A19A8(entries + 0x364, 0);
 fn_27_1A154C(entries + 0x490, 0);
 fn_27_1A1B1C(entries + 0x4ac, 0);
 fn_27_1A1E04(entries + 0x4d8, 0);
 fn_27_1A1C90(entries + 0x544, 0);
 fn_103_788C(modules + 0x87c, modules);
 for (int i = 0; i < 20; ++i) {
  Word entry[5];
  fn_27_AB15C(entry,
   i == 0 ? modules + 0x6e0 :
   i == 1 ? modules + 0x674 :
   i == 2 ? modules + 0x648 :
   i == 3 ? modules + 0x62c :
   i == 4 ? modules + 0x500 :
   i == 5 ? modules + 0x4c4 :
   i == 6 ? modules + 0x4a8 :
   i == 7 ? modules + 0x47c :
   i == 8 ? modules + 0x3f0 :
   i == 9 ? modules + 0x3c4 :
   i == 10 ? modules + 0x3a8 :
   i == 11 ? modules + 0x33c :
   i == 12 ? modules + 0x2f0 :
   i == 13 ? modules + 0x2d4 :
   i == 14 ? modules + 0x2b8 :
   i == 15 ? modules + 0x28c :
   i == 16 ? modules + 0x250 :
   i == 17 ? modules + 0x224 :
   i == 18 ? modules + 0x1b8 :
   i == 19 ? modules + 0x19c : 0);
  reinterpret_cast<Object_vptr_0*>(modules)->fn_103_D35C(entry);
  fn_27_AB18C(entry, -1);
 }
 fn_27_1A3818(object + 0x950, 0);
 *reinterpret_cast<Byte**>(object + 0xdd8) = object + 0xddc;
 fn_27_1A29F0(object + 0xddc, 1, lbl_103_data_0, 0);
 reinterpret_cast<StatusVirtual*>(object + 0xddc)->initialize();
 fn_27_73930(object + 0xdec, owner, object, object + 0x950, object + 0x98,
              object + 0x938, object + 0xdd8, parameters, 0x11f, 1);
 return object;
}