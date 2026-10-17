// Luigi link-event override, .text [0x8208, 0x82A8).
// The published observer thunk subtracts 0x54 before calling this entry.
// Query the sender's original +0x3C dispatch pointer at table offset +0xA8.
// The value 0x74 together with Disconnect_Parent selects the guarded call;
// every other combination forwards the five original argument words once.

#include <so/link/so_link_event_presenter.h>
#include <so/stageobject.h>

class soModuleAccesser;

// Opaque sender ABI view: unused declarations describe the dispatch prefix,
// not implemented methods or a claimed StageObject interface definition.
// getNotifyKind is a local descriptive name for the observed integer query.
struct LuigiLinkEventSender {
    unsigned char m_reserved[0x3c];
    virtual void n00();
    virtual void n01();
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07();
    virtual void n08();
    virtual void n09();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18();
    virtual void n19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual void n26();
    virtual void n27();
    virtual void n28();
    virtual void n29();
    virtual void n30();
    virtual void n31();
    virtual void n32();
    virtual void n33();
    virtual void n34();
    virtual void n35();
    virtual void n36();
    virtual void n37();
    virtual void n38();
    virtual void n39();
    virtual int getNotifyKind();
};

extern "C" {
void fn_27_12D904(void* self, bool arg1, bool arg2, int arg3);
void fn_27_1324D4(void* self, void* event,
                  soModuleAccesser* accesser, void* sender, int argument);
}

extern "C" void fn_99_8208(void* self, void* event,
                           soModuleAccesser* accesser, void* sender,
                           int argument) {
    switch (static_cast<LuigiLinkEventSender*>(sender)->getNotifyKind()) {
    case 0x74:
        switch (static_cast<soLinkEventArgs*>(event)->m_eventKind) {
        case StageObject::Link::Event_Disconnect_Parent:
            fn_27_12D904(self, true, true, 0);
            return;
        default:
            break;
        }
        break;
    }
    fn_27_1324D4(self, event, accesser, sender, argument);
}
