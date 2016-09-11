#include"namevoid.h"
#define  _exec                  _arcane_exec
#define  exec(program, args...) _exec(program, ##args, NULL);
#define  execute                 arcane_execute
#define  find                    arcane_find
#ifdef arcane_enchantment
# define find_enchanted          arcane_find_enchanted
#endif
