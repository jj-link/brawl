// Preserve the original four-byte-aligned integer selector table.
#pragma section data_type ".data$dedede17D58" ".bss"

#include <so/so_module_accesser.h>
#include <StaticAssert.h>

class DededeArticleIntegerSelector {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual const int* getParameters(int kind);
};

struct DededeArticleIntegerAccesser {
    u8 prefix[0xd4];
    DededeArticleIntegerSelector selector;
};
static_assert(sizeof(DededeArticleIntegerAccesser) == 0xd8, "Selector ABI layout");

extern "C" int fn_117_17EE4(DededeArticleIntegerAccesser*, soModuleAccesser*, int, int);

extern "C" int fn_117_17D58(DededeArticleIntegerAccesser* self, soModuleAccesser* accesser, int index, int element) {
    if (index < 24006) {
        return fn_117_17EE4(self, accesser, index, element);
    }
    int kind = accesser->getWorkManageModule().getInt(0x10000005);
    switch (index) {
    case 24007: return self->selector.getParameters(kind)[2];
    case 24008: return self->selector.getParameters(kind)[4];
    case 24009: return self->selector.getParameters(kind)[5];
    case 24010: return self->selector.getParameters(kind)[6];
    case 24011: return self->selector.getParameters(kind)[7];
    case 24012: return self->selector.getParameters(kind)[8];
    case 24013: return self->selector.getParameters(kind)[22];
    case 24014: return self->selector.getParameters(kind)[25];
    case 24015: return self->selector.getParameters(kind)[26];
    default: return 0;
    }
}
