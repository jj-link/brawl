// Keep the switch table four-byte aligned, as in the original REL.
#pragma section data_type ".data$dedede17AAC" ".bss"

#include <so/so_module_accesser.h>
#include <StaticAssert.h>

// The embedded selector supplies the parameter row for the current article kind.
class DededeArticleParameterSelector {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual const float* getParameters(int kind);
};

struct DededeArticleFloatAccesser {
    u8 prefix[0xd4];
    DededeArticleParameterSelector selector;
};
static_assert(sizeof(DededeArticleFloatAccesser) == 0xd8, "Selector ABI layout");

extern "C" {
float fn_117_17D38(DededeArticleFloatAccesser*, soModuleAccesser*, int, int);
extern const float lbl_117_rodata_D0[];

float fn_117_17AAC(DededeArticleFloatAccesser* self, soModuleAccesser* accesser, int index, int element) {
    if (index < 4008) {
        return fn_117_17D38(self, accesser, index, element);
    }
    int kind = accesser->getWorkManageModule().getInt(0x10000005);
    switch (index) {
    case 4009: return self->selector.getParameters(kind)[0];
    case 4010: return self->selector.getParameters(kind)[1];
    case 4011: return self->selector.getParameters(kind)[3];
    case 4012: return self->selector.getParameters(kind)[9];
    case 4013: return self->selector.getParameters(kind)[10];
    case 4014: return self->selector.getParameters(kind)[11];
    case 4015: return self->selector.getParameters(kind)[12];
    case 4016: return self->selector.getParameters(kind)[13];
    case 4017: return self->selector.getParameters(kind)[14];
    case 4018: return self->selector.getParameters(kind)[15];
    case 4019: return self->selector.getParameters(kind)[16];
    case 4020: return self->selector.getParameters(kind)[17];
    case 4021: return self->selector.getParameters(kind)[18];
    case 4022: return self->selector.getParameters(kind)[19];
    case 4023: return self->selector.getParameters(kind)[20];
    case 4024: return self->selector.getParameters(kind)[21];
    case 4025: return self->selector.getParameters(kind)[23];
    case 4026: return self->selector.getParameters(kind)[24];
    default: return lbl_117_rodata_D0[0];
    }
}
}
