#pragma force_active on
extern int lbl_27_data_57EEC;
struct Mid {
    unsigned char unk00[0x1c];
    unsigned short unk1c;
};
class Inner {
public:
    virtual ~Inner();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float getArg(void* arg);

    unsigned char unk04[0x2c - 0x04];
    Mid* unk2c;
};
extern "C" void fn_27_271674(void* self) {
    Inner** a = *(Inner***)((char*)self + 0x14);
    Inner* r3 = a[6];
    Mid* r4 = r3->unk2c;
    unsigned short r31 = r4->unk1c;

    if (r3->getArg(r4) >= (float)r31) {
        *(int*)((char*)self + 4) = lbl_27_data_57EEC;
        *(char*)((char*)self + 0xd) = 1;
    }
}
