// The interface pointer for this entry points 0x70 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the in-module situation handler, forwarding the situation,
// previous-situation and accesser arguments unchanged.
// fn_117_9CEC's verified interface is (void* fighter, int situation,
// int previous, soModuleAccesser* accesser) -> void, defined at
// ft_dedede_function_9cec.cpp; the declaration below repeats that
// definition's parameter types exactly, so the cross-translation-unit
// declarations agree and the forwarded arguments need no conversion.
#include <so/so_module_accesser.h>

extern "C" void fn_117_9CEC(void* fighter, int situation, int previous,
        soModuleAccesser* accesser);

extern "C" void fn_117_E200(void* interface, int situation, int previous,
        soModuleAccesser* accesser) {
    fn_117_9CEC(static_cast<unsigned char*>(interface) - 0x70, situation,
                previous, accesser);
}
