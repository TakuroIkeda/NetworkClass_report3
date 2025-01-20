add_library(report3
  SHARED
    simulate.c
  )
# greetingライブラリのインクルードディレクトリを教えてあげる
# PROJECT_SOURCE_DIRはこのプロジェクトのルートディレクトリの絶対パス
target_include_directories(report3
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  )
