#pragma force_active on
struct Entry { void* object; };
struct Key { short v; Key(const Key& o) : v(o.v) {} };
extern "C" char lbl_27_data_8390[];
class ResultInterface {
public:
    virtual void v0();
    virtual Entry** get(int);
};
struct Result {
    void* vtable;
    void* data;
    unsigned int flags : 12;
    signed int count : 6;
    unsigned int extra : 1;
    unsigned int rest : 13;
    char storage[0x48];
    Result() {
        data = lbl_27_data_8390 + 0x48;
        vtable = lbl_27_data_8390;
        flags = 0;
        count = 0;
        extra = 0;
    }
};
class Interface {
public:
    virtual void find(Key, Result*);
};
struct Manager { char pad[0xc]; Interface interface; };
struct Context { char pad[0x20]; Manager* manager; };
extern "C" const float lbl_27_rodata_9B8[];
extern "C" void fn_27_7030C(void*, int, int, int, float);
extern "C" void fn_27_7021C(void*, int, float);
extern "C" void fn_27_71CA4(Context* self, Key key, int a, int b, unsigned int c, int d) {
    Result result;
    self->manager->interface.find(key, &result);
    while (result.count > 0) {
        fn_27_7030C((*((ResultInterface*)&result)->get(0))->object, a, b, d, lbl_27_rodata_9B8[0]);
        if (c == 1) {
            fn_27_7021C((*((ResultInterface*)&result)->get(0))->object, b, lbl_27_rodata_9B8[0]);
        }
        break;
    }
}
