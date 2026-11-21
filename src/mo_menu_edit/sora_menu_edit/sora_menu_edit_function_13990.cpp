#pragma force_active on
#pragma optimization_level 1
struct Target { char pad[0x350]; int state; };
struct MenuData { char pad0[0x1A0]; void* argument; char pad1[0x1BFC-0x1A4]; int state; char pad2[0x1CE4-0x1C00]; Target* target; };
struct Menu { char pad[0x1AC]; MenuData* data; };
extern "C" void fn_800C6E2C(Target*, void*);
extern "C" void fn_5_13990(Menu* self) {
    MenuData* data = self->data;
    Target* target = data->target;
    if (target->state == 0) {
        data = self->data;
        fn_800C6E2C(target, data->argument);
        self->data->state = 0x1a;
    }
}