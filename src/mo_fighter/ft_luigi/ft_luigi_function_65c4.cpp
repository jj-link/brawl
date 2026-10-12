namespace {
typedef unsigned char Byte;
class ModuleInterface {
public:
    virtual void initialize() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void append(void*) = 0;
};
class EventInterface {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual short eventId() = 0;
};
inline Byte* pointer(Byte* object, int offset) {
    return *reinterpret_cast<Byte**>(object + offset);
}
inline short eventId(Byte* accesser) {
    return reinterpret_cast<EventInterface*>(pointer(pointer(accesser, 0xD8), 0x80) + 8)->eventId();
}
} // namespace
extern "C" {
void fn_27_CD8C8(void*, int);
void fn_27_1A1F78(void*, int);
void fn_99_6760(void*, void*);
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

// Construct the embedded motion arrays and connect them to the module accesser.
extern "C" Byte* fn_99_65C4(Byte* object, Byte* accesser, void* resource) {
    fn_27_CD8C8(object, 0);
    fn_27_1A1F78(object + 0x20, 0);
    fn_99_6760(object + 0xAC, object);
    for (int i = 0; i < 1; ++i) {
        Byte entry[20];
        fn_27_AB15C(entry, i == 0 ? object + 0x20 : 0);
        reinterpret_cast<ModuleInterface*>(object)->append(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_C9E4C(object + 0xC4, 2, 0);
    fn_27_C9630(object + 0x160, 1, 0);
    fn_27_19C7AC(object + 0x198, 0);
    fn_27_1A7584(object + 0x1B8, 5, 0);
    fn_27_C7470(object + 0x1D8, resource, 0x1E2);
    Byte* interpolation = object + 0x1E8;
    fn_27_1A2734(interpolation, 0);
    fn_27_22A24(interpolation + 0x34, interpolation);
    Byte* motion = object + 0x1B8;
    Byte* controller = object + 0x198;
    Byte* nodes = object + 0x160;
    Byte* animations = object + 0xC4;
    Byte* registry = object + 0xAC;
    fn_27_13844(object + 0x224, accesser, object + 0x1D8, registry,
        animations, nodes, controller, motion,
        eventId(accesser),
        1, object + 0x21C);
    reinterpret_cast<ModuleInterface*>(pointer(pointer(accesser, 0xD8), 4))->initialize();
    return object;
}
