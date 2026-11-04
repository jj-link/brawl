#include <so/so_module_accesser.h>
#include <StaticAssert.h>
#pragma force_active on

class PikminArticleFloatSelector {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual const float* getParameters(int kind);
};

struct PikminArticleFloatAccesser {
    u8 prefix[0x158];
    PikminArticleFloatSelector selector;
};
static_assert(sizeof(PikminArticleFloatAccesser) == 0x15c, "Selector ABI layout");

extern "C" float fn_113_22D3C(PikminArticleFloatAccesser*, soModuleAccesser*, int, int);
extern const float lbl_113_rodata_D0[];

extern "C" float fn_113_229B4(PikminArticleFloatAccesser* self, soModuleAccesser* accesser, int index, int element) {
    if (index < 0xFC5) {
        return fn_113_22D3C(self, accesser, index, element);
    }
    int kind = accesser->getWorkManageModule().getInt(0x10000005);
    switch (index) {
    case 0xFC6: return self->selector.getParameters(kind)[1];
    case 0xFC7: return self->selector.getParameters(kind)[2];
    case 0xFC8: return self->selector.getParameters(kind)[3];
    case 0xFC9: return self->selector.getParameters(kind)[4];
    case 0xFCA: return self->selector.getParameters(kind)[5];
    case 0xFCB: return self->selector.getParameters(kind)[6];
    case 0xFCC: return self->selector.getParameters(kind)[7];
    case 0xFCD: return self->selector.getParameters(kind)[8];
    case 0xFCE: return self->selector.getParameters(kind)[9];
    case 0xFCF: return self->selector.getParameters(kind)[10];
    case 0xFD0: return self->selector.getParameters(kind)[11];
    case 0xFD1: return self->selector.getParameters(kind)[12];
    case 0xFD2: return self->selector.getParameters(kind)[13];
    case 0xFD3: return self->selector.getParameters(kind)[14];
    case 0xFD4: return self->selector.getParameters(kind)[15];
    case 0xFD5: return self->selector.getParameters(kind)[16];
    case 0xFD6: return self->selector.getParameters(kind)[17];
    case 0xFD7: return self->selector.getParameters(kind)[18];
    case 0xFD8: return self->selector.getParameters(kind)[20];
    case 0xFD9: return self->selector.getParameters(kind)[21];
    case 0xFDA: return self->selector.getParameters(kind)[22];
    case 0xFDB: return self->selector.getParameters(kind)[23];
    case 0xFDC: return self->selector.getParameters(kind)[24];
    case 0xFDD: return self->selector.getParameters(kind)[25];
    case 0xFDE: return self->selector.getParameters(kind)[26];
    case 0xFDF: return self->selector.getParameters(kind)[27];
    case 0xFE0: return self->selector.getParameters(kind)[28];
    default: return lbl_113_rodata_D0[0];
    }
}