#pragma force_active on
typedef unsigned int u32;
struct Modules;
struct DataInfo { char pad[0x8]; Modules* modules; };
struct Accessor { char pad[0x44]; DataInfo* data; };
struct Entry { char pad[0x30]; u32 flags; };
class Provider { public: virtual void unused(); virtual Entry* get(); };
struct Owner { char pad[0x48]; Provider* provider; };
extern "C" Accessor* fn_27_6F30C(void*);
extern "C" Modules* fn_27_6BC40(Owner self) {
    Entry* entry = self.provider->get();
    if (entry->flags & 1) {
        return fn_27_6F30C((char*)entry + 0x1c)->data->modules;
    }
    return 0;
}
