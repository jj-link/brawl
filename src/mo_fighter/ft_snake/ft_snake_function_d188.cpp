#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_27_131CD0(void*, int);

class FtSubObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(u32 flag);
};

extern "C" void fn_122_D188(void* self, int arg) {
    fn_27_131CD0(self, arg);
    if (arg == 0) {
        FtSubObj* c = *(FtSubObj**)(*(u8**)(*(u8**)((u8*)self + 0x60) + 0xd8) + 0x70);
        int r = c->v16();
        switch (r) {
        case 0x112:
        case 0x113:
        case 0x115:
        case 0x119:
        case 0x11A:
        case 0x11C:
        case 0x11D:
        case 0x11E:
        case 0x11F:
        case 0x120:
        case 0x121:
        case 0x12A:
        case 0x12B:
        case 0x12D:
        case 0x12F: {
            FtSubObj* d = *(FtSubObj**)(*(u8**)(*(u8**)((u8*)self + 0x60) + 0xd8) + 0x64);
            d->v19(0x1200003Du);
            break;
        }
        default:
            break;
        }
    } else if (arg == 3) {
        FtSubObj* d = *(FtSubObj**)(*(u8**)(*(u8**)((u8*)self + 0x60) + 0xd8) + 0x64);
        d->v19(0x1200003Du);
    }
}
