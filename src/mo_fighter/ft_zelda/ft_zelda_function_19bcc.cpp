#pragma force_active on
typedef unsigned char Byte;
class Class_C2D0 {
public:
    virtual void fn_104_1E438();
    virtual void fn_104_1DECC();
    virtual void fn_104_1E358();
    virtual void fn_104_E05C();
    virtual void fn_104_E058();
    virtual void fn_104_E054();
    virtual void fn_104_1DFA0();
    virtual void fn_104_E04C();
    virtual void fn_104_E048();
    virtual void fn_104_E040();
    virtual void fn_104_E03C(void*);
};
class EventManager {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual int getManageId();
};
class Resource {
public:
    virtual void initialize();
};
extern "C" {
void fn_27_CD8C8(void*, int);
void fn_27_1A1F78(void*, int);
void fn_104_7F18(void*, void*);
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
inline Byte* get_controller(Byte* storage) { return storage + 0x1B8; }
inline Byte* get_resource(Byte* storage) { return storage + 0x198; }
inline Byte* get_translation(Byte* storage) { return storage + 0x160; }
inline Byte* get_sequence(Byte* storage) { return storage + 0xC4; }
inline Byte* get_instances(Byte* storage) { return storage + 0xAC; }
inline Byte* get_animation(Byte* storage) { return storage + 0x1E8; }
inline void initializeArray(Byte* storage) {
    Byte entry[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(entry, i == 0 ? storage + 0x20 : 0);
        reinterpret_cast<Class_C2D0*>(storage)->fn_104_E03C(entry);
        fn_27_AB18C(entry, -1);
    }
}
extern "C" void* fn_104_19BCC(Byte* storage, Byte* accesser, void* parameters) {
    fn_27_CD8C8(storage, 0);
    fn_27_1A1F78(storage + 0x20, 0);
    fn_104_7F18(storage + 0xAC, storage);
    initializeArray(storage);
    fn_27_C9E4C(storage + 0xC4, 2, 0);
    fn_27_C9630(storage + 0x160, 1, 0);
    fn_27_19C7AC(storage + 0x198, 0);
    fn_27_1A7584(storage + 0x1B8, 5, 0);
    fn_27_C7470(storage + 0x1D8, parameters, 0x1E6);
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