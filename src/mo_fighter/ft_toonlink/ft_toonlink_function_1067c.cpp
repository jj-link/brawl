#include <so/so_module_accesser.h>
#pragma force_active on

struct FnState121 {
    int a;
    unsigned char b;
    int c;
};

struct ToonLinkEvent121 {
    FnState121 state;
    int nodeId;
    int data[2];
};

extern "C" void fn_121_100DC(FnState121*);

extern "C" void fn_121_1067C(void*, soModuleAccesser* accesser) {
    ToonLinkEvent121 event;
    fn_121_100DC(&event.state);
    event.state.c = 3;
    event.nodeId = accesser->getModelModule().getCorrectNodeId(0x12C);
    accesser->getLinkModule().sendEventNodes(
        0, reinterpret_cast<soLinkEventArgs&>(event), 0);
    accesser->getWorkManageModule().onFlag(0x22000016);
}
