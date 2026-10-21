#pragma force_active on
typedef unsigned int u32;
struct Data {
    unsigned char pad0[0x1A0];
    u32 argument;
    unsigned char pad1[0x1B40 - 0x1A4];
    u32 count;
    unsigned char pad2[0x1CEE - 0x1B44];
    unsigned char flag;
};
struct Base { unsigned char pad[0x3C]; };
struct Object : Base {
    virtual void d0();virtual void d1();virtual void d2();virtual void d3();virtual void d4();
    virtual void d5();virtual void d6();virtual void d7();virtual void d8();virtual void d9();
    virtual void d10();virtual void d11();virtual void d12();virtual void d13();virtual void d14();
    virtual void d15();virtual void d16();virtual void d17();virtual void d18();virtual void d19();
    virtual void d20();virtual void d21();virtual void d22();virtual void d23();virtual void d24();
    virtual void d25();virtual void d26();virtual void d27();virtual void d28();virtual void d29();
    virtual void d30();virtual void d31();virtual void d32();virtual void d33();virtual void d34();
    virtual void d35();virtual void d36();virtual void d37();virtual void d38();virtual void d39();
    virtual void d40();virtual void d41();virtual void d42();virtual void d43();
    virtual u32 query(u32) const;
    unsigned char pad1[0x1AC - 0x40];
    Data* data;
};
extern "C" u32 fn_8_A00(const Object* self) {
    const Data* data = self->data;
    u32 index = data->flag ? data->count - 1 : data->count;
    return index < self->query(data->argument) ? index : 0x80000000;
}
