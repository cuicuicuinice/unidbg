#include "com_github_unidbg_arm_backend_unicorn_Unicorn.h"
#include "khash.h"
#include <unicorn/unicorn.h>

#define SEARCH_BPS_COUNT 8

KHASH_MAP_INIT_INT64(64, char)

typedef struct unicorn {
  khash_t(64) *bps_map;
  uint64_t bps[SEARCH_BPS_COUNT];
  uc_engine *uc;
  jint singleStep;
  jboolean fastDebug;
} *t_unicorn;

struct new_hook {
    uc_hook hh;
    jobject hook;
    t_unicorn unicorn;
};