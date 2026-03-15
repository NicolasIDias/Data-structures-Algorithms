#include "exercise.h"


int can_access_registry(int is_premium, int reputation, int has_2fa){
  if(is_premium || reputation >= 100 && has_2fa) return 1;
  else return 0;
}
