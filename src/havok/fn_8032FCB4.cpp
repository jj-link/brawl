#pragma force_active on
struct Header { char pad[0x14]; int count; };
struct Owner { char pad[0xc]; Header* header; };
extern "C" int fn_80330A24(Owner*, void*, int*);
extern "C" int fn_80330B94(Owner*, void*, int);
extern "C" int fn_80330E54(Owner*, void*, int, int);
extern "C" int fn_803310D0(Owner*);
extern "C" int fn_8032FCB4(Owner* self, void* stream) {
    if (fn_80330A24(self, stream, 0) == 0 && fn_80330B94(self, stream, 0) == 0) {
        for (int i = 0; i < self->header->count; i++) {
            if (fn_80330E54(self, stream, i, 0) == 1)
                return 1;
        }
        return fn_803310D0(self) == 1;
    }
    return 1;
}