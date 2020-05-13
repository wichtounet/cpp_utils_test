default: release

.PHONY: default release debug all clean doc

include make-utils/flags.mk
include make-utils/cpp-utils.mk

# Use C++20
$(eval $(call use_cpp20))

WARNING_FLAGS += -pedantic
CXX_FLAGS += -Iinclude -ICatch/single_include -Werror

LD_FLAGS += -pthread

# Enable coverage if not disabled by the user
ifeq (,$(CPP_UTILS_NO_COVERAGE))
ifneq (,$(findstring clang,$(CXX)))
DEBUG_FLAGS += -fprofile-arcs -ftest-coverage
else
ifneq (,$(findstring g++,$(CXX)))
DEBUG_FLAGS += --coverage
endif
endif
endif

# Compile the tests and create the executables
$(eval $(call auto_folder_compile,test))
$(eval $(call auto_add_executable,test))

release: release_test
release_debug: release_debug_test
debug: debug_test

clang-tidy:
	@ /usr/share/clang/run-clang-tidy.py -p . -header-filter '^include/cpp_utils' -checks='cert-*,cppcoreguidelines-*,google-*,llvm-*,misc-*,modernize-*,performance-*,readility-*,-cppcoreguidelines-pro-type-reinterpret-cast,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-google-readability-namespace-comments,-llvm-namespace-comment,-llvm-include-order,-google-runtime-references' -j9 2>/dev/null  | /usr/bin/zgrep -v "^clang-tidy"

clang-tidy-all:
	@ /usr/share/clang/run-clang-tidy.py -p . -header-filter '^include/cpp_utils' -checks='*' -j9

clang-tidy-mono:
	clang-tidy -p . -header-filter '^include/cpp_utils' -checks='cert-*,cppcoreguidelines-*,google-*,llvm-*,misc-*,modernize-*,performance-*,readility-*,-cppcoreguidelines-pro-type-reinterpret-cast,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-google-readability-namespace-comments,-llvm-namespace-comment,-llvm-include-order,-google-runtime-references' test/*.cpp

clang-tidy-mono-all:
	clang-tidy -p . -header-filter '^include/cpp_utils' -checks='*' test/*.cpp

all: release release_debug debug

debug_test: debug/bin/test
	./debug/bin/test

release_test: release/bin/test
	./release/bin/test

release_debug_test: release_debug/bin/test
	./release_debug/bin/test

cpp_test: debug/bin/test release_debug/bin/test release/bin/test
	./debug/bin/test
	./release_debug/bin/test
	./release/bin/test

doc:
	doxygen Doxyfile

clean: base_clean
	rm -rf doc

include make-utils/cpp-utils-finalize.mk
