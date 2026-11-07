#pragma force_active on
typedef unsigned char Byte;
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(void*);
};
class EventManager {
public:
 virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
 virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual int getManageId();
};
class Resource { public: virtual void initialize(); };
extern "C" {
void fn_27_CD8C8(void*, int);
void fn_27_1A1F78(void*, int);
void fn_102_6790(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_C9E4C(void*, int, int);
void fn_27_C9630(void*, int, int);
void fn_27_19C7AC(void*, int);
void fn_27_1A7584(void*, int, int);
void fn_27_C7470(void*, void*, int);
void fn_27_1A2734(void*, int);
void fn_27_22A24(void*, void*);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, short, int, void*);
}
inline Byte* get_animation(Byte* p) { return p + 0x1E8; }
inline Byte* get_controller(Byte* p) { return p + 0x1B8; }
inline Byte* get_resource(Byte* p) { return p + 0x198; }
inline Byte* get_translation(Byte* p) { return p + 0x160; }
inline Byte* get_sequence(Byte* p) { return p + 0xC4; }
inline Byte* get_instances(Byte* p) { return p + 0xAC; }
inline void initializeArray(Byte* storage) {
 Byte entry[0x14];
 for (int i = 0; i < 1; ++i) {
  fn_27_AB15C(entry, i == 0 ? storage + 0x20 : 0);
  reinterpret_cast<Object_vptr_0*>(storage)->slot10(entry);
  fn_27_AB18C(entry, -1);
 }
}
extern "C" void* fn_102_12484(Byte* storage, Byte* accesser, void* parameters) {
 fn_27_CD8C8(storage, 0);
 fn_27_1A1F78(storage + 0x20, 0);
 fn_102_6790(storage + 0xAC, storage);
 initializeArray(storage);
 fn_27_C9E4C(storage + 0xC4, 2, 0);
 fn_27_C9630(storage + 0x160, 1, 0);
 fn_27_19C7AC(storage + 0x198, 0);
 fn_27_1A7584(storage + 0x1B8, 5, 0);
 fn_27_C7470(storage + 0x1D8, parameters, 0x1E4);
 Byte* animation = get_animation(storage);
 fn_27_1A2734(animation, 0);
 fn_27_22A24(animation + 0x34, animation);
 Byte* controller = get_controller(storage);
 Byte* resource = get_resource(storage);
 Byte* translation = get_translation(storage);
 Byte* sequence = get_sequence(storage);
 Byte* instances = get_instances(storage);
 fn_27_13844(storage + 0x224, accesser, storage + 0x1D8,
  instances, sequence, translation, resource, controller,
  static_cast<short>(reinterpret_cast<EventManager*>(
   *reinterpret_cast<Byte**>(*reinterpret_cast<Byte**>(accesser + 0xD8) + 0x80) + 8)->getManageId()),
  1, storage + 0x21C);
 reinterpret_cast<Resource*>(
  *reinterpret_cast<Byte**>(*reinterpret_cast<Byte**>(accesser + 0xD8) + 4))->initialize();
 return storage;
}