
#pragma force_active on
#pragma optimization_level 1
typedef struct Node
{
  int unk0;
  int unk4;
  int id;
  int *state;
  int value;
} Node;
extern Node **fn_80397570(void);
extern int fn_80397580(void *);
extern void fn_8039094C(void);
extern void fn_80390950(int);
extern void fn_80392664(int, int *, int);
extern void *fn_80397568(void *);
extern int fn_80390788(void *, int, int);
int fn_80391A20(void *arg0, int arg1)
{
  int ctx;
  int result = 0;
  Node *node;
  Node **pp;
  Node *new_var;
  pp = fn_80397570();
  ctx = fn_80397580(arg0);
  node = *pp;
  new_var = node;
  fn_8039094C();
  if (((new_var != 0) && (node->id == arg1)) && ((*new_var->state) == 0))
  {
    *new_var->state = 1;
    fn_80392664(ctx, new_var->state, node->value);
    result = 1;
  }
  if (result == 0)
  {
    result = fn_80390788(fn_80397568(arg0), ctx, arg1);
  }
  fn_80390950(ctx);
  return result;
}
