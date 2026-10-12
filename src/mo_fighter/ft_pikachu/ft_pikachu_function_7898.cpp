// Fixed embedded motion-module storage initialized by Pikachu's module aggregate.
// Constructors in sora_melee retain their original external ABI names.
typedef unsigned char Byte;
class PikachuStorageArray {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void append(void*);
};
class PikachuStorageEventManager {
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
class PikachuStorageResource {
public:
    virtual void initialize();
};
extern "C" {
void fn_27_CD8C8(void*, int);
void fn_27_1A1F78(void*, int);
void fn_98_7A34(void*, void*);
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

extern "C" void* fn_98_7898(Byte* storage, Byte* accesser, void* parameters) {
    Byte entry[0x14];
    fn_27_CD8C8(storage, 0);
    fn_27_1A1F78(storage + 0x20, 0);
    fn_98_7A34(storage + 0xAC, storage);
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(entry, i == 0 ? storage + 0x20 : 0);
        reinterpret_cast<PikachuStorageArray*>(storage)->append(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_C9E4C(storage + 0xC4, 2, 0);
    fn_27_C9630(storage + 0x160, 1, 0);
    fn_27_19C7AC(storage + 0x198, 0);
    fn_27_1A7584(storage + 0x1B8, 5, 0);
    fn_27_C7470(storage + 0x1D8, parameters, 0x1E6);
    Byte* animation = storage + 0x1E8;
    fn_27_1A2734(animation, 0);
    fn_27_22A24(animation + 0x34, animation);
    Byte* controller = storage + 0x1B8;
    Byte* resource = storage + 0x198;
    Byte* translation = storage + 0x160;
    Byte* sequence = storage + 0xC4;
    Byte* instances = storage + 0xAC;
    fn_27_13844(storage + 0x224, accesser, storage + 0x1D8,
        instances, sequence, translation, resource, controller,
        static_cast<short>(reinterpret_cast<PikachuStorageEventManager*>(
            *reinterpret_cast<Byte**>(*reinterpret_cast<Byte**>(accesser + 0xD8) + 0x80) + 8)->getManageId()),
        1, storage + 0x21C);
    reinterpret_cast<PikachuStorageResource*>(
        *reinterpret_cast<Byte**>(*reinterpret_cast<Byte**>(accesser + 0xD8) + 4))->initialize();
    return storage;
}
