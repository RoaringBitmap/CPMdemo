#include "roaring.h"
#include "roaring.hh"
#include "roaring64map.hh"
#include <cstdio>
#include <iostream>

int main() {
  // C demo
  {
    roaring_bitmap_t *r1 = roaring_bitmap_create();
    for (uint32_t i = 100; i < 1000; i++)
      roaring_bitmap_add(r1, i);
    printf("cardinality = %d\n", (int)roaring_bitmap_get_cardinality(r1));
    roaring_bitmap_free(r1);

    bitset_t *b = bitset_create();
    for (int k = 0; k < 1000; ++k) {
      bitset_set(b, 3 * k);
    }
    printf("%zu \n", bitset_count(b));
    bitset_free(b);
  }
  // C++ demo
  {
    roaring::Roaring r1;
    for (uint32_t i = 100; i < 1000; i++) {
      r1.add(i);
    }
    std::cout << "cardinality = " << r1.cardinality() << std::endl;
    roaring::Roaring64Map r2;
    for (uint64_t i = 18000000000000000100ull; i < 18000000000000001000ull;
         i++) {
      r2.add(i);
    }
    std::cout << "cardinality = " << r2.cardinality() << std::endl;
  }
  return EXIT_SUCCESS;
}