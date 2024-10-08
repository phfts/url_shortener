#define CROW_USE_BOOST 1

#include <gtest/gtest.h>

#include "./controllers/urls_controller_tests.cpp"
#include "./helpers/hash_helper.cpp"
#include "./models/urls.cpp"
#include "./repository/document_store.cpp"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}