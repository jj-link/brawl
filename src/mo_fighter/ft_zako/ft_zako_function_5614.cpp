#pragma force_active on
typedef unsigned char Byte;
class ZakoArray { public: virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C(); virtual void append(void*); };
class ZakoEventManager { public: virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual int getManageId(); };
class ZakoResource { public: virtual void initialize(); };
extern "C" {
void fn_27_CD8C8(void*, int); void fn_27_1A1F78(void*, int); void fn_126_57B0(void*, void*); void fn_27_AB15C(void*, void*); void fn_27_AB18C(void*, short); void fn_27_C9E4C(void*, int, int); void fn_27_19838C(void*, int, int); void fn_27_19C7AC(void*, int); void fn_27_1A7584(void*, int, int); void fn_27_C7470(void*, void*, int); void fn_27_1A2734(void*, int); void fn_27_22A24(void*, void*); void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, short, int, void*);
}
inline void initializeArray(Byte* object) {
    Byte entry[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(entry, i == 0 ? object + 0x20 : 0);
        reinterpret_cast<ZakoArray*>(object)->append(entry);
        fn_27_AB18C(entry, -1);
    }
}
inline Byte* get_animation(Byte* p) { return p + 0x214; }
inline Byte* get_controller(Byte* p) { return p + 0x1E4; }
inline Byte* get_resource(Byte* p) { return p + 0x1C4; }
inline Byte* get_translation(Byte* p) { return p + 0x160; }
inline Byte* get_sequence(Byte* p) { return p + 0xC4; }
inline Byte* get_instances(Byte* p) { return p + 0xAC; }
extern "C" void* fn_126_5614(Byte* object, Byte* accesser, void* parameters) {
    fn_27_CD8C8(object, 0);
    fn_27_1A1F78(object + 0x20, 0);
    fn_126_57B0(object + 0xAC, object);
    initializeArray(object);
    fn_27_C9E4C(object + 0xC4, 2, 0);
    fn_27_19838C(object + 0x160, 2, 0);
    fn_27_19C7AC(object + 0x1C4, 0);
    fn_27_1A7584(object + 0x1E4, 5, 0);
    fn_27_C7470(object + 0x204, parameters, 0x1CF);
    Byte* animation = get_animation(object);
    fn_27_1A2734(animation, 0);
    fn_27_22A24(animation + 0x34, animation);
    Byte* controller = get_controller(object);
    Byte* resource = get_resource(object);
    Byte* translation = get_translation(object);
    Byte* sequence = get_sequence(object);
    Byte* instances = get_instances(object);
    short id = reinterpret_cast<ZakoEventManager*>(
        *reinterpret_cast<Byte**>(*reinterpret_cast<Byte**>(accesser + 0xD8) + 0x80) + 8
    )->getManageId();
    fn_27_13844(object + 0x250, accesser, object + 0x204, instances, sequence,
        translation, resource, controller, id, 1, object + 0x248);
    reinterpret_cast<ZakoResource*>(
        *reinterpret_cast<Byte**>(*reinterpret_cast<Byte**>(accesser + 0xD8) + 4)
    )->initialize();
    return object;
}