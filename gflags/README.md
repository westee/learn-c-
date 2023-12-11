1. 下载gflags `git clone https://github.com/gflags/gflags.git`
2. `mkdir -p build` 创建build目录
3. `cd build`
4`cmake ..`, 其中`..`是CMakeLists.txt所在的目录
5`cmake --build . -j 8` // 并发度为8，make clean可以清除生成的文件。
6`sudo cmake --install .` 安装，会执行`cmake_install.cmake`文件
```txt
-- Install configuration: "Release"
-- Installing: /usr/local/lib/libgflags.a
-- Installing: /usr/local/lib/libgflags_nothreads.a
-- Installing: /usr/local/include/gflags/gflags.h
-- Installing: /usr/local/include/gflags/gflags_declare.h
-- Installing: /usr/local/include/gflags/gflags_completions.h
-- Installing: /usr/local/include/gflags/gflags_gflags.h
-- Installing: /usr/local/lib/cmake/gflags/gflags-config.cmake
-- Installing: /usr/local/lib/cmake/gflags/gflags-config-version.cmake
-- Installing: /usr/local/lib/cmake/gflags/gflags-targets.cmake
-- Installing: /usr/local/lib/cmake/gflags/gflags-targets-release.cmake
-- Installing: /usr/local/lib/cmake/gflags/gflags-nonamespace-targets.cmake
-- Installing: /usr/local/lib/cmake/gflags/gflags-nonamespace-targets-release.cmake
-- Installing: /usr/local/bin/gflags_completions.sh
-- Installing: /usr/local/lib/pkgconfig/gflags.pc
-- Installing: /home/sunshine/.cmake/packages/gflags/e5f7ce61772240490d3164df06f58ce9
```
## 用法
```c++
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
```
1. 文件中读取
```bash
./l_gflags -flagfile=../commandArgs.txt
```
文件内容
```txt
--BOUND=11
--CONTENT=hello
```
2. 环境变量
```bash
export FLAGS_CONTENT=env
./l_gflags --fromenv=CONTENT
```
### 引用特定版本

将`gflags`下载到项目根目录`third_party`下`git clone https://github.com/gflags/gflags.git`
```txt
cmake_minimum_required(VERSION 3.16.3)
project(l_gflags)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party/gflags)

add_executable(l_gflags main.cpp)

target_link_libraries(l_gflags gflags_nothreads_static)
```