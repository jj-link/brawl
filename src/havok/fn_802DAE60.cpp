#pragma force_active on
#pragma fp_contract on

#include <types.h>

class Class_80487A40 {
public:
    virtual void fn_802DAC40();
    virtual void fn_80080A64();
    virtual void fn_802DBC28();
    virtual void fn_802DAD74();
    virtual void fn_802DAE14();
    virtual char* fn_802DB8AC(int);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
};

extern "C" {
    int fn_80289814(void*);
    void fn_80288B40(void*, void*, int, int);
    int fn_80295108(void*);
    void fn_8028965C(void*, void*);
    void* fn_802DB97C(void*, int);
    void fn_802DB984(void*, void*);
    void fn_8028D8B4(void*, int);
    void fn_802DB990(void*, int);
    int fn_80295120(void*);
    char* fn_802DB9AC(void*);
    char* fn_802DB55C();
    void* fn_802DB9B4(void*);
    char* fn_802DB564(void*, int);
    int fn_802DB56C(void*);
    void fn_802DB9BC(void*, int);
    void fn_802DBA6C(void*, int);
    char** fn_802DBAD4(void*, int);
    void* fn_802DB574(void*);
    void fn_8029875C(void*, void*);
    int fn_80295110(void*);
    void* fn_802DB57C(void*, void*, int);
    void fn_802DBAE4(void*, void*);
    int fn_802DB588(void*);
    void fn_802DBB04(void*, int);
    void fn_802DBB0C(void*, void*);
    void* fn_802DB590(void*);
    void* fn_80296ED8(void*, int);
    void fn_80295138(void*, void*);
    void fn_802DBB28(void*, void*);
    void fn_8029873C(void*, float);
    void fn_802DBB34(void*, void*);
    void fn_802DBB40(void*, void*);
    void fn_802DBB4C(void*, void*);
    void fn_802DB598(void*);
    char* fn_802DAD64(void*, int);
    int fn_802DBBB8(void*);
    void fn_802DB59C(void*, int, void*);
    void fn_8028D8BC(void*);
    void fn_8028F1A8(void*, void*, void*, void*, float);
    void fn_80295140(void*, int);
    void fn_802DB620(void*);
    void* fn_802DBBC0(void*);
    int fn_802DB624(void*);
    void fn_8028590C(void*, int);
    int fn_802A0BD8(void*);
    void fn_802DB910(void*, void*);
    void fn_802DB628(void*, void*, void*);
    void fn_802DAD7C(void*, void*);
    int fn_802DBBC8(void*);
    char* fn_802DB6E4(void*, int);
    void fn_802DB6D0(void*, float, float, float, float);
    float fn_802DB704(void*);
    float* fn_80297488(void*, int);
    void fn_802DB728(void*, void*, void*);
    void fn_802DB804(void*, void*);
    void fn_802DB848(void*, void*);
    void fn_802DB878(void*);
    void fn_80285A6C(void*, void*);
    int fn_802DB8A0(void*, int);
    void fn_802DB87C(void*, int);
    int fn_802DAE54(void*);
    void fn_802DBBD0(void*);
    void fn_802887A8(void*, void*, int, void*);
    void fn_802DBBE0(void*, void*);
    float* fn_800966A4(void*, int);
    void fn_802951A0(void*, void*, void*);
    u8& fn_802DBBF4(void*, int);
    void fn_802DB8B4(void*, void*, void*, void*);
    void fn_802DBC04(void*, void*);
    u8* fn_802DAE40(void*, int);
    int fn_802DBC10(void*);
    int fn_802DBC18(void*);
    void fn_80290594(void*, void*, void*);
    void fn_802DB9D8(void*, int);
    void fn_8028D8A0();
    void fn_802DAA68(void*, int);

    extern float lbl_805A4268;
    extern float lbl_805A426C;
}

union LocalStorage {
    char data[0xBF0];
    struct {
        char beforeTransform[0x170];
        char transform[0x40];
    } layout;
    int scratch;
} __attribute__((aligned(16)));

#define LOCAL(n) (s + ((n) - 0x10))

extern "C" void fn_802DAE60(void* arg0, void* arg1, void* arg2)
{
    int saved;
    int initial;
    char* base;
    char* owner;
    char* items;
    int count;
    int i;
    char* first;
    void* value;
    float zero;
    int j;
    u8* bytes;
    LocalStorage storage;
    char* s = storage.data;
    char* context = (char*)arg2;
    char* input = (char*)arg1;
    char* object = (char*)arg0;
    union { int previousOffset; u8 byte; };

    fn_80288B40(input, context, fn_80289814(input + 0x44), 8);
    saved = fn_80295108(context + 8);
    fn_8028965C(LOCAL(0x180), input);
    fn_802DB984(LOCAL(0x1C0), fn_802DB97C(LOCAL(0x18), 0));
    fn_8028D8B4(LOCAL(0x1C4), 0);
    fn_802DB990(LOCAL(0x1E0), 0);
    initial = fn_80295120(context);
    owner = fn_802DB9AC(input + 0x40);
    first = fn_802DB55C();
    base = fn_802DB564(fn_802DB9B4(input + 0x28), -*(int*)(first + 0x1B0));
    items = owner + 0x2C;
    count = fn_802DB56C(items) - 1;
    fn_802DB9BC(LOCAL(0x26C), 0);
    fn_802DBA6C(LOCAL(0x26C), count);

    first = *fn_802DBAD4(items, 0);
    {
        value = fn_802DB574(first);
        fn_8029875C(LOCAL(0x1AC), fn_802DB564(base, *(int*)(first + 0x1B0)));
        fn_802DBAE4(LOCAL(0x1E0),
                     fn_802DB57C(LOCAL(0x14), base, fn_80295110(LOCAL(0x1AC))));
        fn_802DBB04(LOCAL(0x1B4), fn_802DB588(value));
    }

    fn_802DBB0C(LOCAL(0xD0), context);
    fn_80295138(LOCAL(0xD0), fn_80296ED8(fn_802DB590(context), count * 0x90));
    fn_802DBB28(LOCAL(0x19C), LOCAL(0x188));
    fn_8029873C(LOCAL(0x1A0), lbl_805A4268);

    zero = lbl_805A426C;
    i = 0;
    previousOffset = 0;
    for (; i < count; previousOffset += 0x10, ++i) {
        char* item;
        void* value;
        char* entry;
        char* rotation;
        float* previous;

        fn_802DBB34(LOCAL(0x1A8), LOCAL(0x1AC));
        fn_802DBB40(LOCAL(0x1B0), LOCAL(0x1B4));
        item = *fn_802DBAD4(items, i + 1);
        value = fn_802DB574(item);
        fn_8029875C(LOCAL(0x1AC), fn_802DB564(base, *(int*)(item + 0x1B0)));
        fn_802DBB4C(LOCAL(0x1E0),
                     fn_802DB57C(&storage.scratch, base, fn_80295110(LOCAL(0x1AC))));
        fn_802DBB04(LOCAL(0x1B4), fn_802DB588(value));

        fn_802DB598(LOCAL(0xC0));
        entry = fn_802DAD64(object + 0x18, i);
        fn_802DB59C(LOCAL(0xC0), fn_802DBBB8(LOCAL(0x1B0)), entry);
        fn_802DB598(LOCAL(0xB0));
        entry = fn_802DAD64(object + 0x18, i);
        fn_802DB59C(LOCAL(0xB0), fn_802DBBB8(LOCAL(0x1B4)), entry + 0x10);
        fn_8028D8BC(LOCAL(0x180));
        fn_8028F1A8(LOCAL(0xC0), LOCAL(0xB0), LOCAL(0x180), context,
                    *(float*)(object + 0x3C));
        fn_80295140(context + 8, saved);

        fn_802DB620(LOCAL(0xA0));
        fn_8028590C(LOCAL(0xA0), fn_802DB624(fn_802DBBC0(LOCAL(0x1B0))));
        fn_802DB620(LOCAL(0x90));
        fn_8028590C(LOCAL(0x90), fn_802DB624(fn_802DBBC0(LOCAL(0x1B4))));
        if (fn_802A0BD8(fn_802DAD64(object + 0x18, i) + 0x4C)) {
            fn_802DB910(LOCAL(0xA0), LOCAL(0x90));
        }

        fn_802DB620(LOCAL(0x80));
        fn_802DB628(LOCAL(0x80), LOCAL(0x90),
                     fn_802DAD64(object + 0x18, i) + 0x30);
        fn_802DAD7C(LOCAL(0x90), LOCAL(0x80));
        rotation = fn_802DAD64(object + 0x18, i) + 0x20;
        previous = (float*)(fn_802DB6E4(object, fn_802DBBC8(input + 0x44)) + previousOffset);
        fn_802DB620(LOCAL(0x70));
        fn_802DB6D0(LOCAL(0x70), previous[0], previous[1], previous[2], previous[3]);
        if (zero == fn_802DB704(LOCAL(0x70))) {
            fn_802DAD7C(LOCAL(0x70), rotation);
        }
        fn_802DB620(LOCAL(0x60));
        fn_802DB628(LOCAL(0x60), LOCAL(0xA0), rotation);
        fn_802DB620(LOCAL(0x50));
        fn_802DB628(LOCAL(0x50), LOCAL(0xA0), LOCAL(0x70));
        previous[0] = *fn_80297488(rotation, 0);
        previous[1] = *fn_80297488(rotation, 1);
        previous[2] = *fn_80297488(rotation, 2);
        previous[3] = *fn_80297488(rotation, 3);

        fn_802DB598(LOCAL(0x40));
        fn_802DB728(LOCAL(0x90), LOCAL(0x60), LOCAL(0x40));
        fn_802DB598(LOCAL(0x30));
        fn_802DB728(LOCAL(0x90), LOCAL(0x50), LOCAL(0x30));
        fn_802DB804(LOCAL(0x40), LOCAL(0x30));
        if (fn_802A0BD8(fn_802DAD64(object + 0x18, i) + 0x4C)) {
            fn_802DB848(LOCAL(0x40), LOCAL(0x40));
            fn_802DB848(LOCAL(0x30), LOCAL(0x30));
        }

        fn_802DB878(LOCAL(0x150));
        fn_80285A6C(LOCAL(0x150), LOCAL(0x90));
        j = 0;
        do {
            char* table;
            fn_802DB87C(LOCAL(0x20), fn_802DB8A0(LOCAL(0x150), j));
            table = ((Class_80487A40*)object)->fn_802DB8AC(fn_802DAE54(owner));
            fn_802DBBD0(LOCAL(0xF8));
            fn_802887A8(LOCAL(0x20), LOCAL(0x180), fn_80295120(LOCAL(0xD0)),
                        LOCAL(0xF8));
            *(void**)LOCAL(0xFC) = storage.layout.transform;
            fn_802DBBE0(LOCAL(0x100), table + (j + (i * 6 + 3)) * 8);
            *(float*)LOCAL(0x108) = *fn_800966A4(LOCAL(0x40), j);
            *(float*)LOCAL(0x10C) = *fn_800966A4(LOCAL(0x30), j);
            entry = fn_802DAD64(object + 0x18, i);
            fn_802951A0(*(void**)(entry + 0x40 + j * 4), LOCAL(0xF8), LOCAL(0xE0));
            fn_802DB8B4(LOCAL(0xE0), storage.layout.transform, LOCAL(0xD0),
                         &fn_802DBBF4(LOCAL(0x26C), i) + j * 0x18 + 4);
            fn_80295140(LOCAL(0xD8), saved);
            ++j;
        } while (j < 3);
    }

    fn_802DBC04(context, LOCAL(0xD0));
    bytes = fn_802DAE40(object, fn_802DAE54(owner));
    u8* cursor;
    for (int copyIndex = 0; cursor = bytes + copyIndex, copyIndex < count; ++copyIndex) {
        byte = *cursor;
        fn_802DBBF4(LOCAL(0x26C), copyIndex) = byte;
    }

    *(int*)LOCAL(0x110) = count;
    *(float*)LOCAL(0x114) = *(float*)(object + 0x24);
    *(float*)LOCAL(0x118) = *(float*)(object + 0x28);
    *(float*)LOCAL(0x11C) = *(float*)(object + 0x2C);
    *(float*)LOCAL(0x120) = *(float*)(object + 0x30);
    *(float*)LOCAL(0x124) = *(float*)(object + 0x34);
    *(float*)LOCAL(0x128) = *(float*)(object + 0x38);
    *(int*)LOCAL(0x12C) = fn_802DBC10(LOCAL(0x1E0));
    *(void**)LOCAL(0x130) = base;
    *(int*)LOCAL(0x134) = fn_802DBC18(LOCAL(0x26C));
    *(float*)LOCAL(0x138) = lbl_805A426C;
    *(u8**)LOCAL(0x13C) = bytes;
    *(int*)LOCAL(0x140) = initial;
    fn_80290594(LOCAL(0x110), input, context);
    fn_802DB9D8(LOCAL(0x26C), -1);
    fn_8028D8A0();
    fn_802DAA68(LOCAL(0x1E0), -1);
}
