#include <stdio.h>
#include <stdarg.h>
#include "config.h"

int main(int argc, char **argv) {
	printf("Performance A380 - Projet MGA803\n");
  
  // report version
  printf(" Version %d.%d.%d.%d\n\n", Performances_A380_VERSION_MAJOR, Performances_A380_VERSION_MINOR, Performances_A380_VERSION_PATCH, Performances_A380_VERSION_TWEAK);
  
  if (argc > 1) {
    // printf(" Version %d.%d.%d.%d", 0, 1, 0, 0);
    printf("Usage: %s\n", argv[0]);
		return 1;
  }
	return 0;
}
