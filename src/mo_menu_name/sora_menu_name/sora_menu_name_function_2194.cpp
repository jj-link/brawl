#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_800B8EDC(void*, void*);
void exit__6gfTaskFv(void*);

void fn_16_2194(void* self)
{
    if (*reinterpret_cast<void**>(reinterpret_cast<u8*>(self) + 0x154)) {
        u8* cursor = reinterpret_cast<u8*>(self);
        for (int i = 0; i < 19; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x40);
            if (entry) {
                fn_800B8EDC(
                    *reinterpret_cast<void**>(reinterpret_cast<u8*>(self) + 0x154),
                    entry);
            }
        }
    }
    exit__6gfTaskFv(self);
}
}
