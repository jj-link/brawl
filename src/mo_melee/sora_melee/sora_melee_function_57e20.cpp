#pragma force_active on
extern "C" void addTail__6utListFP10utListNode(void* list, void* node);

extern "C" void fn_27_57E20(char* self, int index)
{
    char* base = *(char**)(self + 4);
    addTail__6utListFP10utListNode(self + 0xC, base + index * 0x14);
}
