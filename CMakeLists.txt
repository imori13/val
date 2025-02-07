cmake_minimum_required(VERSION 3.16)

project(MyVulkanProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

# ビルド生成物を build ディレクトリ配下にまとめる
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# source/ 以下の全ソースファイルを収集
file(GLOB_RECURSE HEADERS "include/core/*.h")
file(GLOB_RECURSE SOURCES "source/*.cpp" "source/core/*.cpp")

# 必要なライブラリを検索（vcpkg 経由の場合も自動設定される）
find_package(glfw3 CONFIG REQUIRED)
find_package(VulkanHeaders CONFIG)
find_package(Vulkan REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# include/ ディレクトリを公開インクルードパスに追加
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/core
)

# GLFW と Vulkan の実装ライブラリをリンク
target_link_libraries(${PROJECT_NAME} PRIVATE glfw Vulkan::Vulkan)

# プリコンパイル済みヘッダーを設定 (CMake 3.16 以上)
target_precompile_headers(${PROJECT_NAME} PRIVATE "include/pch.h")