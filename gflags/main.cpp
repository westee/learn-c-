#include <iostream>
#include <gflags/gflags.h>

DEFINE_int32(BOUND, 1000, "xxx");
DEFINE_string(CONTENT, "xxx", "this is word");

int main(int argc, char *argv[]) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    for (int i = fLI::FLAGS_BOUND - 1; i >= 0; i--) {
        std::cout << fLS::FLAGS_CONTENT << i << std::endl;
    }
    return 0;
}