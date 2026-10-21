#pragma force_active on

typedef unsigned int u32;

struct Header {
    u32 a, b;
};

struct Info {
    u32 id, value;
};

class Input : public Header {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual u32 fetch(Info*, int);
};

class BaseItem;

class Module : public Header {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual int test(BaseItem*, int);
};

struct Modules {
    char pad[0x10];
    Module* module;
};

struct Context {
    char pad[0xd8];
    Modules* modules;
};

struct ItemHeader {
    char pad[0x3c];
};

class BaseItem : public ItemHeader {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual u32 get();
};

struct Result {
    u32 id;
    BaseItem* item;
    int param;
    u32 value;
    unsigned char active : 1;
    unsigned char flag : 1;
    unsigned char kind : 6;

    void set(u32 a, BaseItem* b, int c, u32 d) {
        id = a;
        item = b;
        param = c;
        value = d;
        active = 1;
        flag = 0;
        kind = 0xfe;
    }
};

extern "C" void* getInstance__9itManagerFv();
extern "C" BaseItem* fn_27_2A88C4(void*, u32);
extern "C" int getParam__8BaseItemFQ215itValueAccesser8ParamInt(BaseItem*, int);

extern "C" bool fn_27_BE760(void*, Input* input, Result* out, Context* context) {
    Info info;
    if (input->fetch(&info, -1) == 1) {
        BaseItem* item = fn_27_2A88C4(getInstance__9itManagerFv(), info.id);
        if (item) {
            if (context->modules->module->test(item, 0) == 0) {
                out->set(
                    item->get(),
                    item,
                    getParam__8BaseItemFQ215itValueAccesser8ParamInt(item, 0x5bce),
                    info.value
                );
                return true;
            }
        }
    }
    return false;
}
