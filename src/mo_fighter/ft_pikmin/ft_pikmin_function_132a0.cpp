#pragma force_active on
class ElemArray {
public:
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void** slot04(int index) = 0;
    virtual int slot05() = 0;
};

class Mod {
public:
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void slot04() = 0;
    virtual void* slot05(int, bool, bool) = 0;
    virtual int slot06(int, int) = 0;
    virtual void slot07(int, unsigned int) = 0;
    virtual void slot08() = 0;
    virtual void slot09() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15(void*) = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
    virtual void slot26() = 0;
    virtual void slot27() = 0;
    virtual void slot28() = 0;
    virtual void slot29() = 0;
    virtual void slot30() = 0;
    virtual void slot31() = 0;
    virtual void slot32() = 0;
    virtual void slot33() = 0;
    virtual void slot34() = 0;
    virtual void slot35() = 0;
    virtual void slot36() = 0;
    virtual void slot37() = 0;
    virtual void slot38() = 0;
    virtual void slot39() = 0;
    virtual void slot40() = 0;
    virtual void slot41() = 0;
    virtual void slot42() = 0;
    virtual void slot43() = 0;
    virtual void slot44() = 0;
    virtual void slot45() = 0;
    virtual void slot46() = 0;
    virtual void slot47() = 0;
    virtual void slot48() = 0;
    virtual void slot49() = 0;
    virtual void slot50() = 0;
    virtual void slot51() = 0;
    virtual void slot52() = 0;
    virtual void slot53() = 0;
    virtual void slot54() = 0;
    virtual void slot55() = 0;
    virtual void slot56() = 0;
    virtual void slot57() = 0;
    virtual void slot58() = 0;
    virtual void slot59() = 0;
    virtual void slot60() = 0;
    virtual void slot61() = 0;
    virtual void slot62() = 0;
    virtual void slot63() = 0;
    virtual void slot64() = 0;
    virtual void slot65() = 0;
    virtual void slot66() = 0;
    virtual void slot67() = 0;
    virtual void slot68() = 0;
    virtual void slot69() = 0;
    virtual void slot70() = 0;
    virtual void slot71() = 0;
    virtual void slot72() = 0;
    virtual void slot73() = 0;
    virtual void slot74() = 0;
    virtual void slot75() = 0;
    virtual void slot76() = 0;
    virtual void slot77() = 0;
    virtual void slot78() = 0;
    virtual void slot79() = 0;
    virtual void slot80() = 0;
    virtual void slot81() = 0;
    virtual void slot82() = 0;
    virtual void slot83() = 0;
    virtual void slot84() = 0;
    virtual void slot85() = 0;
    virtual void slot86() = 0;
    virtual void slot87() = 0;
    virtual void slot88() = 0;
    virtual void slot89() = 0;
    virtual void slot90() = 0;
    virtual void slot91() = 0;
    virtual void slot92() = 0;
    virtual void slot93() = 0;
    virtual void slot94() = 0;
    virtual void slot95() = 0;
    virtual void slot96() = 0;
    virtual void slot97() = 0;
    virtual void slot98() = 0;
    virtual void slot99() = 0;
    virtual void slot100() = 0;
    virtual void slot101(int, int, int) = 0;
};

struct FtModules {
    unsigned char pad00[0x54];
    Mod* m54;
    unsigned char pad58[0x0C];
    Mod* m64;
    unsigned char pad68[0x1C];
    Mod* m84;
};

struct FtObject {
    unsigned char pad00[0xD8];
    FtModules* modules;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_4FAB4(void*);
int fn_27_5013C(void*);
int fn_113_243BC(void*);
void fn_113_243DC(void*, int);
int fn_113_243CC(void*);
void* fn_113_24550(void*);
void fn_113_24D54(void*, void*, int, int, int);
extern void* lbl_27_bss_B8;
extern const char lbl_113_data_65B0[];
extern const char lbl_113_data_2244[];
}

extern "C" void fn_113_132A0(void* arg0, void* arg1) {
    FtObject* obj = static_cast<FtObject*>(arg1);
    obj->modules->m64->slot07(-1, 0x10000042);
    void* base = *reinterpret_cast<void**>(static_cast<unsigned char*>(arg0) + 4);
    fn_113_243DC(base, fn_113_243BC(base));
    if (fn_113_243CC(*reinterpret_cast<void**>(static_cast<unsigned char*>(arg0) + 4)) > 0) {
        void* found = obj->modules->m84->slot05(2, false, false);
        void* b = __dynamic_cast(found, 0, lbl_113_data_65B0, lbl_113_data_2244, 0);
        if (b != 0) {
            obj->modules->m84->slot15(static_cast<unsigned char*>(b) + 0x88);
            if (lbl_27_bss_B8 == 0) {
                void* x = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
                if (x != 0) {
                    x = fn_27_4FAB4(x);
                }
                lbl_27_bss_B8 = x;
            }
            int r28 = fn_27_5013C(lbl_27_bss_B8);
            if (r28 >= 0) {
                obj->modules->m64->slot07(r28, 0x10000042);
            } else {
                obj->modules->m64->slot07(-1, 0x10000042);
            }
            ElemArray* arr = static_cast<ElemArray*>(
                fn_113_24550(*reinterpret_cast<void**>(static_cast<unsigned char*>(arg0) + 4)));
            int base2 = *reinterpret_cast<int*>(static_cast<unsigned char*>(b) + 0x28);
            int i = 0;
            while (i < arr->slot05()) {
                void* elem = *arr->slot04(i);
                fn_113_24D54(*reinterpret_cast<void**>(static_cast<unsigned char*>(arg0) + 4), elem, base2, 0xA - i, r28);
                int idx = i + 7;
                if (obj->modules->m54->slot06(idx, *reinterpret_cast<int*>(static_cast<unsigned char*>(elem) + 0x28)) == 0) {
                    break;
                }
                obj->modules->m54->slot101(idx, 0, 1);
                i++;
            }
        }
    }
}
