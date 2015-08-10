default: release

.PHONY: default release debug all clean

include make-utils/flags.mk
include make-utils/cpp-utils.mk

WARNING_FLAGS += -pedantic
CXX_FLAGS += -Iinclude -ICatch/include -Werror

ifneq (,$(findstring clang,$(CXX)))
CXX_FLAGS += -stdlib=libc++
endif

ifneq (,$(findstring c++-analyzer,$(CXX)))
CXX_FLAGS += -stdlib=libc++
endif

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

clean: base_clean

include make-utils/cpp-utils-finalize.mk
