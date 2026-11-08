#pragma force_active on
extern "C" {
struct Vec2 { float x; float y; };
struct Pair2 { int x; int y; };
extern float lbl_41_rodata_C38[];
void* fn_41_15FD4(void*, int);
bool fn_41_1AE7C(void*);
int fn_41_1C840(void*, void*);
void fn_41_1592C(Vec2*, const Vec2*);
void fn_41_1CC18(void*);
bool fn_41_1794C(void*, int);
void* fn_41_15964(void*, int);
float fn_41_15A00(Vec2*);
void fn_41_17C30(void*, int);
void fn_41_1C95C(void*, Vec2*, float);
void fn_41_1627C(void*, int, int, int, bool, bool, float, int, float, float);
class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual Pair2 getPair();
    virtual void slot3();
    virtual void slot4();
    virtual void fn_41_12100();
    virtual void fn_41_13608();
    virtual void fn_41_13600();
    virtual void fn_41_135BC();
    virtual void fn_41_12784();
};
class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
};
void fn_41_17614(void* arg0, int arg1, int arg2, int arg3) {
    float* base = lbl_41_rodata_C38;
    Vec2 accumulated;
    accumulated.x = base[1];
    accumulated.y = base[1];
    int i = 0;
    while (i < 8) {
        soAnimCmdEventObserver* observer = (soAnimCmdEventObserver*)fn_41_15FD4(arg0, i);
        if (fn_41_1AE7C(observer) != true &&
            fn_41_1C840(observer, *(void**)((char*)arg0 + 0x20)) != 0) {
            Pair2 value = observer->getPair();
            fn_41_1592C(&accumulated, (Vec2*)&value);
            fn_41_1CC18(observer);
        }
        i++;
    }
    if (fn_41_1794C(arg0, arg1) != 0) {
        void* record = fn_41_15964(arg0, arg2);
        if (*(int*)record == 0 || *(int*)record == 8 || *(int*)record == 9 ||
            *(int*)record == 10 || *(int*)record == 11 ||
            *(int*)record == 12 || *(int*)record == 13) {
            if (base[13] == *(float*)((char*)record + 4) ||
                base[14] == *(float*)((char*)record + 4) ||
                base[15] == *(float*)((char*)record + 4)) {
                float amount = *(float*)((char*)record + 0x24);
                if (base[14] == amount) {
                    void* module = *(void**)((char*)arg0 + 0x20);
                    void* mid = *(void**)((char*)module + 0xd8);
                    Class_6E20* object = *(Class_6E20**)((char*)mid + 0xc);
                    object->fn_41_350CC();
                    Pair2 source = *(Pair2*)&accumulated;
                    Pair2 temp = source;
                    amount = fn_41_15A00((Vec2*)&temp);
                }
                fn_41_17C30(arg0, arg1);
                fn_41_1C95C(fn_41_15FD4(arg0, arg1), &accumulated, amount);
                fn_41_1627C(arg0, arg1, arg2, (int)record, 0, 0, amount, arg3,
                            base[0], base[1]);
            }
        }
    }
}
}