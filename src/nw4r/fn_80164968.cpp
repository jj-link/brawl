#pragma force_active on
class Entity;
extern "C" void* fn_8016E4E8();
extern "C" int fn_8016E9CC(void*, const void*, int);
extern "C" void fn_8015BFB4(void*, void*);
struct Entity_base { char pad[0x0c]; int field_0c; char pad2[0x0c]; };
class Entity : public Entity_base {
public:
 virtual void f0(); virtual void f1(); virtual int f2(int, int, void*);
 char pad3[0x20]; int field_40;
};
class Command {
public:
 virtual void f0(); virtual void f1(); virtual Entity* f2(); virtual void f3(void*);
};
struct Context { Command* command; char pad[0x5014]; char* array; };
extern "C" Entity* fn_80164968(Context* ctx, const void* arg1, unsigned int arg2, void* arg3) {
 char* elem = (char*)arg3;
 int result;
 Entity* ent;
 void* base = fn_8016E4E8();
 result = fn_8016E9CC(base, arg1, 0);
 if (result == 0) return 0;
 ent = ctx->command->f2();
 if (ent == 0) return 0;
 if (ent->f2((int)ctx, result, elem) == 0) {
  ctx->command->f3(ent);
  return 0;
 }
 ent->field_40 = arg2;
 unsigned int offset = arg2 * 0x1c;
 elem = ctx->array + offset;
 fn_8015BFB4(elem, ent);
 *(unsigned short*)(elem + 0x18) += 1;
 ent->field_0c = 1;
 char* elem2 = ctx->array + offset;
 *(unsigned short*)(elem2 + 0x18) -= 1;
 ent->field_0c = 2;
 return ent;
}